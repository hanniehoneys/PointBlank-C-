#include <Network/ServerPacket/PROTOCOL_BASE_URL_LIST_ACK.hpp>
#include <AuthManager.hpp>
#include <Protocol/Acknowledge.hpp>
#include <Managers/Server/ServerConfig.hpp>

PROTOCOL_BASE_URL_LIST_ACK::PROTOCOL_BASE_URL_LIST_ACK()
: AckPacketInterface(eProtocolPacketAck::BASE_URL_LIST_ACK, 0) {
    auto* pConfig = GetAuthManager()->GetServerConfig();
    AckPacketInterface::Reserve(22 + pConfig->GetWebsiteURL().length() + pConfig->GetCommunityURL().length());
}

void PROTOCOL_BASE_URL_LIST_ACK::Build() {
    auto* pConfig = GetAuthManager()->GetServerConfig();
    std::string websiteUrl = pConfig->GetWebsiteURL();
    std::string communityUrl = pConfig->GetCommunityURL();

    Write<std::uint8_t>(1);
    Write<std::uint8_t>(2);
    Write<std::uint16_t>(websiteUrl.length());
    Write<std::uint64_t>(4L);
    Write<char>(websiteUrl.data(), websiteUrl.size());
    Write<std::uint16_t>(communityUrl.length());
    Write<std::uint64_t>(3L);
    Write<char>(communityUrl.data(), communityUrl.size());
}