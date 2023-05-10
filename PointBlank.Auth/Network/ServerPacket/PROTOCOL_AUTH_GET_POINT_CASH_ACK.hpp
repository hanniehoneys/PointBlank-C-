#pragma once
#include <cstdint>
#include <string>
#include <Network/PacketInterface.hpp>
#include <Models/Enums/EventResult.hpp>

class PROTOCOL_AUTH_GET_POINT_CASH_ACK : public AckPacketInterface {
public:
    PROTOCOL_AUTH_GET_POINT_CASH_ACK(const eEventResult& result, const std::int32_t& point, const std::int32_t& cash);
    ~PROTOCOL_AUTH_GET_POINT_CASH_ACK() = default;
};