#include <Network/ServerPacket/PROTOCOL_BASE_GET_SYSTEM_INFO_ACK.hpp>
#include <Protocol/Acknowledge.hpp>
#include <AuthManager.hpp>
#include <Data/ServersInfo.hpp>
#include <Data/ChannelsInfo.hpp>
#include <Data/RanksInfo.hpp>
#include <Data/MissionsInfo.hpp>
#include <Managers/ShopManager.hpp>
#include <Managers/Server/ServerConfig.hpp>

PROTOCOL_BASE_GET_SYSTEM_INFO_ACK::PROTOCOL_BASE_GET_SYSTEM_INFO_ACK()
: AckPacketInterface(eProtocolPacketAck::BASE_GET_SYSTEM_INFO_ACK, 0) {
    auto exitUrl = GetAuthManager()->GetServerConfig()->GetExitURL();
    AckPacketInterface::Reserve(this->GetMemoryUsage());
    
    Write<std::uint16_t>(0);
    Write<std::uint8_t>(0);
    Write<std::uint8_t>(5);
    Write<std::uint8_t>(10);
    Write<std::uint8_t>(32);
    Write<std::uint8_t>(4);
    Write<std::uint8_t>(0);
    Write<std::uint8_t>(1);
    Write<std::uint8_t>(2);
    Write<std::uint8_t>(5);
    Write<std::uint8_t>(3);
    Write<std::uint8_t>(6);
    MemorySet(0, 25);
    Write<std::uint8_t>(7);
    MemorySet(0, 229);
    Write<std::uint32_t>(171718655);
    Write<std::uint8_t>(3);
    Write<std::uint32_t>(600);
    Write<std::uint32_t>(2400);
    Write<std::uint32_t>(6000);
    Write<std::uint8_t>(0);
    Write<std::uint16_t>(GetMissionsInfo()->GetPageBits(0));
    Write<std::uint16_t>(GetMissionsInfo()->GetPageBits(1));
    Write<std::uint16_t>(29890);

    Write<std::uint8_t>(static_cast<uint8_t>(GetServersInfo()->GetServersCount()));
    for (const auto& server : GetServersInfo()->GetServers()) {
        auto addressBytes = server.m_endpoint.address().to_v4().to_bytes();

        Write<std::uint32_t>(server.m_state);
        Write(addressBytes.data(), addressBytes.size());
        Write<std::uint16_t>(server.m_port);
        Write<std::uint8_t>(server.m_type);
        Write<std::uint16_t>(server.m_maxPlayers);
        Write<std::uint32_t>(server.m_lastCount);

        std::vector<ChannelData> channels = GetChannelsInfo()->GetChannels(server.m_id);
        for (const auto& channel : channels)
            Write<std::uint8_t>(channel.m_type);
    }

    Write<std::uint16_t>(exitUrl.size());
    Write<char>(exitUrl.data(), exitUrl.size());

    Write<std::uint8_t>(51);
    for (auto rankId = 0; rankId < 52; ++rankId) {
        auto awards = GetRanksInfo()->GetAwards(rankId);
        Write<std::uint8_t>(rankId);
        for (const auto& item : awards) {
            auto* goodItem = GetShopManager()->GetItem(item.GetID());
            if (!goodItem)
                Write<std::uint32_t>(0);
            else
                Write<std::uint32_t>(goodItem->m_id);
        }
        for (auto awardsCount = awards.size(); 4 - awardsCount > 0; ++awardsCount)
          Write<std::uint32_t>(0);
    }
    Write<std::uint8_t>(1);

    AckPacketInterface::Pack();
}

std::size_t PROTOCOL_BASE_GET_SYSTEM_INFO_ACK::GetMemoryUsage() {
    std::size_t dataLength = 297 + GetAuthManager()->GetServerConfig()->GetExitURL().size();
    
    
    for (const auto& server : GetServersInfo()->GetServers()) {
        auto addressBytes = server.m_endpoint.address().to_v4().to_bytes();
        dataLength += 13 + addressBytes.size() + GetChannelsInfo()->GetChannelsCount(server.m_id);
    }
    for (auto rankId = 0; rankId < 52; ++rankId) {
        auto awards = GetRanksInfo()->GetAwards(rankId);
        dataLength++;
        for (const auto& item : awards)
            dataLength += 4;
        for (auto awardsCount = awards.size(); 4 - awardsCount > 0; ++awardsCount)
            dataLength += 4;
    }

    return dataLength;
}