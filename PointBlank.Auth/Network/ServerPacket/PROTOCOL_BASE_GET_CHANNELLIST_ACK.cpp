#include <Network/ServerPacket/PROTOCOL_BASE_GET_CHANNELLIST_ACK.hpp>
#include <Protocol/Acknowledge.hpp>
#include <Data/ChannelsInfo.hpp>

PROTOCOL_BASE_GET_CHANNELLIST_ACK::PROTOCOL_BASE_GET_CHANNELLIST_ACK(std::vector<ChannelData> channels)
: AckPacketInterface(eProtocolPacketAck::BASE_GET_CHANNELLIST_ACK, 0), m_channels(channels) {
    AckPacketInterface::Reserve(this->GetMemoryUsage());

    Write<std::uint16_t>(0);
    Write<std::uint8_t>(0);
    Write<std::uint8_t>(channels.size());
    for (const auto& channel : channels)
        Write<std::uint16_t>(channel.m_players);
    Write<std::uint16_t>(100); //max players per channel
    Write<std::uint8_t>(channels.size());

    AckPacketInterface::Pack();
}

std::size_t PROTOCOL_BASE_GET_CHANNELLIST_ACK::GetMemoryUsage() {
    std::size_t dataLength = 7 + (m_channels.size() * 2);
    return dataLength;
}