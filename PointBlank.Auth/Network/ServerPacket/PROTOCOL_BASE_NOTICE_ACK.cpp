#include <Network/ServerPacket/PROTOCOL_BASE_NOTICE_ACK.hpp>
#include <AuthManager.hpp>
#include <Protocol/Acknowledge.hpp>
#include <Managers/Server/ServerConfig.hpp>

PROTOCOL_BASE_NOTICE_ACK::PROTOCOL_BASE_NOTICE_ACK()
: AckPacketInterface(eProtocolPacketAck::BASE_NOTICE_ACK, 0) {
    auto* pConfig = GetAuthManager()->GetServerConfig();
    std::string chatMessage = pConfig->GetChatMessage();
    std::string announceMessage = pConfig->GetAnnounceMessage();

    AckPacketInterface::Reserve(14 + chatMessage.length() + announceMessage.length());
    
    Write<std::uint16_t>(0); //i guess this might be some color
    Write<std::uint32_t>(pConfig->GetChatColor());
    Write<std::uint32_t>(pConfig->GetAnnounceColor());
    Write<char>(chatMessage.data(), chatMessage.size());
    Write<char>(announceMessage.data(), announceMessage.size());

    AckPacketInterface::Pack();
}