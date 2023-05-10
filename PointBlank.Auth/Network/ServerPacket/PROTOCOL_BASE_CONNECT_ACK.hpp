#pragma once
#include <cstdint>
#include <Network/PacketInterface.hpp>

class PROTOCOL_BASE_CONNECT_ACK : public AckPacketInterface {
public:
    PROTOCOL_BASE_CONNECT_ACK(const uint16_t& sessionSeed, const uint32_t& sessionId);
    ~PROTOCOL_BASE_CONNECT_ACK() = default;
};