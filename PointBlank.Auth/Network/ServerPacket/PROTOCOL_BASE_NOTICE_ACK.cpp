#include <Network/ServerPacket/PROTOCOL_BASE_NOTICE_ACK.hpp>
#include <AuthManager.hpp>
#include <Protocol/Acknowledge.hpp>
#include <Managers/Server/ServerConfig.hpp>

PROTOCOL_BASE_NOTICE_ACK::PROTOCOL_BASE_NOTICE_ACK()
: AckPacketInterface(eProtocolPacketAck::BASE_NOTICE_ACK, 0) {
    auto* pConfig = GetAuthManager()->GetServerConfig();
    AckPacketInterface::Reserve(14 + pConfig->GetChatMessage().length() + pConfig->GetAnnounceMessage().length());
}

void PROTOCOL_BASE_NOTICE_ACK::Build() {
    auto* pConfig = GetAuthManager()->GetServerConfig();

    Write<std::uint16_t>(0); //i guess this might be some color
    Write<std::uint32_t>(pConfig->GetChatColor());
    Write<std::uint32_t>(pConfig->GetAnnounceColor());
    Write<std::uint16_t>(pConfig->GetChatMessage());
    Write<std::uint16_t>(pConfig->GetAnnounceMessage());
}