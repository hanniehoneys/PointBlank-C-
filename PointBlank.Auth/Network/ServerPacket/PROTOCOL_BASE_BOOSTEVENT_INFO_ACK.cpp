#include <Network/ServerPacket/PROTOCOL_BASE_BOOSTEVENT_INFO_ACK.hpp>
#include <Protocol/Acknowledge.hpp>

PROTOCOL_BASE_BOOSTEVENT_INFO_ACK::PROTOCOL_BASE_BOOSTEVENT_INFO_ACK()
: AckPacketInterface(eProtocolPacketAck::BASE_BOOSTEVENT_INFO_ACK, 9) {
    Write<std::uint64_t>(1L);
    Write<std::uint8_t>(0);

    AckPacketInterface::Pack();
}