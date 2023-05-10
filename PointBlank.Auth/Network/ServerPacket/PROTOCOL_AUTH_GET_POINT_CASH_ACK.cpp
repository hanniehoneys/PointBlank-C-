#include <Network/ServerPacket/PROTOCOL_AUTH_GET_POINT_CASH_ACK.hpp>
#include <Protocol/Acknowledge.hpp>

PROTOCOL_AUTH_GET_POINT_CASH_ACK::PROTOCOL_AUTH_GET_POINT_CASH_ACK(const eEventResult& result, const std::int32_t& point, const std::int32_t& cash)
: AckPacketInterface(eProtocolPacketAck::AUTH_GET_POINT_CASH_ACK, 8 + (result == eEventResult::SUCCESS ? 8 : 0)) { 
    Write<std::uint32_t>(static_cast<uint32_t>(result));
    if (result == eEventResult::SUCCESS) {
        Write<std::int32_t>(point);
        Write<std::int32_t>(cash);
    }
    Write<std::uint32_t>(0);

    AckPacketInterface::Pack();
}