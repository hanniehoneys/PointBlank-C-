#pragma once
#include <vector>
#include <string>
#include <cstring>

class BinaryWriter {
public:
    void Reserve(std::size_t size) {
        m_buffer = std::vector<uint8_t>(size);
    }

    template <typename T>
    void Write(T val) {
        std::memcpy(m_buffer.data() + m_position, &val, sizeof(T));
        m_position += sizeof(T);
    }
    template <typename T>
    void Write(const T* val, std::size_t dataLength) {
        std::memcpy(m_buffer.data() + m_position, val, dataLength);
        m_position += dataLength;
    }
    template <typename T>
    void Write(const std::vector<T>& val) {
        m_buffer.insert(m_buffer.end(), val.begin(), val.end());
    }
    void Write(const char* val, std::size_t dataLength) {
        std::memcpy(m_buffer.data() + m_position, val, dataLength);
        m_position += dataLength;
    }
    void MemorySet(const std::int32_t& data, const std::size_t& length) {
        std::memset(m_buffer.data() + m_position, data, length);
        m_position += length;
    }

    void Skip(std::size_t length) { 
        m_position += length; 
    }


    uint8_t* Get() { return m_buffer.data(); }
    std::vector<uint8_t> GetBuffer() { return m_buffer; }
    std::size_t GetSize() const { return m_buffer.size(); }
    std::size_t GetPosition() const { return m_position; }
    
public:
    BinaryWriter() : m_buffer(0), m_position(0) {
        //
    }
    BinaryWriter(std::size_t size) : m_buffer(size), m_position(0) {
        //
    }
    ~BinaryWriter() {
        m_buffer.clear();
    }
    
private:
    std::vector<uint8_t> m_buffer;
    std::size_t m_position;
};