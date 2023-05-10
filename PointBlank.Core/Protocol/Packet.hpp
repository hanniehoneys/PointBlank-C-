#pragma once
#include <cstdint>
#include <vector>

class Packet {
public:
    static std::vector<uint8_t> Decrypt(const std::vector<uint8_t>& data, int32_t shift) {
        std::vector<uint8_t> buffer(data.size());
        std::memcpy(buffer.data(), data.data(), buffer.size());

        uint8_t temporaryValue = buffer[buffer.size() - 1];
        for (int index = buffer.size() - 1; index > 0; --index)
            buffer[index] = ((buffer[index - 1] & 0xFF) << (8 - shift)) | ((buffer[index] & 0xFF) >> shift);

        buffer[0] = (temporaryValue << (8 - shift)) | ((buffer[0] & 0xFF) >> shift);

        return buffer;
    }
};