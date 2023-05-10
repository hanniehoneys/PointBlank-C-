#pragma once
#include <vector>
#include <cstdint>
#include <memory>
#include <string>

class BinaryReader {
public:
    template <typename T>
    T Read() {
        T val;
        std::memcpy(&val, m_buffer.data() + m_position, sizeof(T));
        m_position += sizeof(T);
        return val;
    }
    std::vector<uint8_t> ReadBytes(std::uint32_t bytes) {
        std::vector<uint8_t> val(m_buffer.begin() + m_position, m_buffer.begin() + m_position + bytes);
        m_position += bytes;
        return val;
    }
    template <typename dataType>
    std::string ReadString() {
        dataType length = this->Read<dataType>();   
        std::string str = std::string(reinterpret_cast<char*>(m_buffer.data() + m_position), length);
        m_position += length;
        return str;
    }
    std::string ReadString(std::uint16_t length) {
        std::string str = std::string(reinterpret_cast<char*>(m_buffer.data() + m_position), length);
        if (str.find('\0') != std::string::npos)
            str = str.substr(0, str.find('\0'));
        m_position += length;
        return str;
    }

    void Skip(std::size_t length) { m_position += length; }

    std::uint8_t* GetData() { return m_buffer.data(); }
    std::vector<uint8_t> GetBuffer() { return m_buffer; }
    std::size_t GetPosition() const { return m_position; }

public:
    BinaryReader(std::vector<uint8_t> buffer, std::size_t offset = 0) : m_buffer(buffer), m_position(offset) {
        //
    }
    ~BinaryReader() = default;

private:
    std::vector<uint8_t> m_buffer;
    std::size_t m_position;
};
