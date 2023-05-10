#include <Network/ServerPacket/PROTOCOL_BASE_GET_SYSTEM_INFO_ACK.hpp>
#include <Protocol/Acknowledge.hpp>
#include <AuthManager.hpp>
#include <Data/MissionsInfo.hpp>
#include <Data/ServersInfo.hpp>
#include <Data/ChannelsInfo.hpp>
#include <Managers/Server/ServerConfig.hpp>

PROTOCOL_BASE_GET_SYSTEM_INFO_ACK::PROTOCOL_BASE_GET_SYSTEM_INFO_ACK()
: AckPacketInterface(eProtocolPacketAck::BASE_GET_SYSTEM_INFO_ACK, 0) {
    std::size_t dataLength = 297;
    
    for (const auto& server : GetServersInfo()->GetServers()) {
        auto addressBytes = server.m_endpoint.address().to_v4().to_bytes();
        dataLength += 13 + addressBytes.size() + GetChannelsInfo()->GetChannels(server.m_id).size();
    }

    AckPacketInterface::Reserve(dataLength);
}

void PROTOCOL_BASE_GET_SYSTEM_INFO_ACK::Build() {
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

    Write<std::uint16_t>(GetAuthManager()->GetServerConfig()->GetExitURL());

    Write<std::uint8_t>(0);
    Write<std::uint8_t>(1);
    /*
      this.writeC((byte) 51);
      for (int rank = 0; rank < 52; ++rank)
      {
        List<ItemsModel> awards = RankXml.getAwards(rank);
        this.writeC((byte) rank);
        for (int index = 0; index < awards.Count; ++index)
        {
          ItemsModel itemsModel = awards[index];
          if (ShopManager.getItemId(itemsModel._id) == null)
            this.writeD(0);
          else
            this.writeD(ShopManager.getItemId(itemsModel._id).id);
        }
        for (int count = awards.Count; 4 - count > 0; ++count)
          this.writeD(0);
      }
      this.writeC((byte) 1);
    */
}