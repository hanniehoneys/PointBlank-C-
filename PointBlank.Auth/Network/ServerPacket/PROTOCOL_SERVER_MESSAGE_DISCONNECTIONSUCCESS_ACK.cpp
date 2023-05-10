#include <Network/ServerPacket/PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK.hpp>
#include <Core.hpp>
#include <Protocol/Acknowledge.hpp>

PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK::PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK(const uint32_t& flags, const bool& usingHack) 
: AckPacketInterface(eProtocolPacketAck::SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK, usingHack ? 16 : 12) {
    Write<std::uint32_t>(static_cast<uint32_t>(std::time(nullptr)));
    //Write<std::uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(system_clock::now().time_since_epoch()).count());
    Write<std::uint32_t>(flags);
    Write<std::uint32_t>(usingHack);
    if (!usingHack)
        return;
    Write<std::uint32_t>(0);
    
    AckPacketInterface::Pack();
}