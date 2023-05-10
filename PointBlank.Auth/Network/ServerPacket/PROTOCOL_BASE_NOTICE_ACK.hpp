#pragma once
#include <cstdint>
#include <string>
#include <Network/PacketInterface.hpp>

class PROTOCOL_BASE_NOTICE_ACK : public AckPacketInterface {
public:
    PROTOCOL_BASE_NOTICE_ACK();
    ~PROTOCOL_BASE_NOTICE_ACK() = default;
};