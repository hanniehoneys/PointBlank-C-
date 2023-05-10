#pragma once
#include <cstdint>
#include <Network/PacketInterface.hpp>

class PROTOCOL_BASE_GET_SYSTEM_INFO_ACK : public AckPacketInterface {
public:
    PROTOCOL_BASE_GET_SYSTEM_INFO_ACK();
    ~PROTOCOL_BASE_GET_SYSTEM_INFO_ACK() = default;

private:
    std::size_t GetMemoryUsage();
};