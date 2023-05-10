#include <Network/ClientPacket/PROTOCOL_BASE_GET_CHANNELLIST_REQ.hpp>
#include <Logger.hpp>
#include <Utilities/Utils.hpp>
#include <Network/ServerPacket/ServerPackets.hpp>
#include <AuthClient.hpp>
#include <Data/ChannelsInfo.hpp>

PROTOCOL_BASE_GET_CHANNELLIST_REQ::PROTOCOL_BASE_GET_CHANNELLIST_REQ(AuthClient* client, const std::vector<uint8_t>& buffer) 
: ReqPacketInterface(client, buffer) {
    m_serverId = Read<std::uint32_t>();
}

void PROTOCOL_BASE_GET_CHANNELLIST_REQ::Run() {
    auto channels = GetChannelsInfo()->GetChannels(m_serverId);
    for (auto channel : channels)
        Logger::Print("Channel[{}]: {}", channel.m_id, channel.m_type);
    if (!m_pClient->GetAccount())
        return;
        
    m_pClient->SendPacket(PROTOCOL_BASE_GET_CHANNELLIST_ACK(channels));
}