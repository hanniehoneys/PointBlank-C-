#include <Network/ServerPacket/PROTOCOL_BASE_CHANNELTYPE_CONDITION_ACK.hpp>
#include <Protocol/Acknowledge.hpp>

PROTOCOL_BASE_CHANNELTYPE_CONDITION_ACK::PROTOCOL_BASE_CHANNELTYPE_CONDITION_ACK()
: AckPacketInterface(eProtocolPacketAck::BASE_CHANNELTYPE_CONDITION_ACK, 888) {
    MemorySet(0, 888);

    AckPacketInterface::Pack();
}