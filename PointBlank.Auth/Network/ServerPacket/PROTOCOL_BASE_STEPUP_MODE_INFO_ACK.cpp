#include <Network/ServerPacket/PROTOCOL_BASE_STEPUP_MODE_INFO_ACK.hpp>
#include <Protocol/Acknowledge.hpp>

PROTOCOL_BASE_STEPUP_MODE_INFO_ACK::PROTOCOL_BASE_STEPUP_MODE_INFO_ACK()
: AckPacketInterface(eProtocolPacketAck::BASE_STEPUP_MODE_INFO_ACK, 4) {
    Write<std::uint32_t>(0);

    AckPacketInterface::Pack();
}