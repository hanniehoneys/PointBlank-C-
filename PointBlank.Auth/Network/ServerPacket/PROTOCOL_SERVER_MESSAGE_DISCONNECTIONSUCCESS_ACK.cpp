#include <Network/ServerPacket/PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK.hpp>
#include <Core.hpp>
#include <Protocol/Acknowledge.hpp>

PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK::PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK(const uint32_t& flags, const bool& usingHack) 
: AckPacketInterface(eProtocolPacketAck::SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK, m_bUsingHack ? 16 : 12) {
    m_flags = flags;
    m_bUsingHack = usingHack;
}

void PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK::Build() {
    Write<std::uint32_t>(static_cast<uint32_t>(std::time(nullptr)));
    //Write<std::uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(system_clock::now().time_since_epoch()).count());
    Write<std::uint32_t>(m_flags);
    Write<std::uint32_t>(m_bUsingHack);

    if (!m_bUsingHack)
        return;

    Write<std::uint32_t>(0);
}