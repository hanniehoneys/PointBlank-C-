#include <Network/ServerPacket/PROTOCOL_AUTH_GET_POINT_CASH_ACK.hpp>
#include <Protocol/Acknowledge.hpp>

PROTOCOL_AUTH_GET_POINT_CASH_ACK::PROTOCOL_AUTH_GET_POINT_CASH_ACK(const eEventResult& result, const std::int32_t& point, const std::int32_t& cash)
: AckPacketInterface(eProtocolPacketAck::AUTH_GET_POINT_CASH_ACK, 8 + (m_result == eEventResult::SUCCESS ? 8 : 0)) {
    m_result = result;
    m_point = point;
    m_cash = cash;
}

void PROTOCOL_AUTH_GET_POINT_CASH_ACK::Build() {
    Write<std::uint32_t>(static_cast<uint32_t>(m_result));
    if (m_result == eEventResult::SUCCESS) {
        Write<std::int32_t>(m_point);
        Write<std::int32_t>(m_cash);
    }
    Write<std::uint32_t>(0);
}