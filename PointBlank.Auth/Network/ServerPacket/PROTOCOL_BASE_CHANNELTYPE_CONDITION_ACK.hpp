#pragma once
#include <cstdint>
#include <string>
#include <Network/PacketInterface.hpp>

class PROTOCOL_BASE_CHANNELTYPE_CONDITION_ACK : public AckPacketInterface {
public:
    PROTOCOL_BASE_CHANNELTYPE_CONDITION_ACK();
    ~PROTOCOL_BASE_CHANNELTYPE_CONDITION_ACK() = default;
};