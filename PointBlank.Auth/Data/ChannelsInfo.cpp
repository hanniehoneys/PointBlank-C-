#include <Data/ChannelsInfo.hpp>
#include <sqlpp11/sqlpp11.h>
#include <Database/Database.hpp>
#include <Database/Interface/ChannelsInfoInterface.hpp>

ChannelsInfo g_channelsInfo;
ChannelsInfo* GetChannelsInfo() {
    return &g_channelsInfo;
}

void ChannelsInfo::Load(std::uint8_t serverId) {
    ChannelsInfoDB channelsInfo{};
    for (const auto &row : (*GetDatabase()->GetConnection())(select(all_of(channelsInfo)).from(channelsInfo).where(
        channelsInfo.serverId == serverId
    ).order_by(channelsInfo.id.asc()))) {
        ChannelData channel {
            .m_id = static_cast<std::uint32_t>(row.id),
            .m_type = static_cast<std::uint32_t>(row.type),
            .m_serverId = static_cast<std::uint32_t>(row.serverId),
            .m_announceMessage = row.announceMessage
        };
        m_channels.push_back(std::move(channel));
    }
}

std::vector<ChannelData> ChannelsInfo::GetChannels() {
    return m_channels;
}
std::vector<ChannelData> ChannelsInfo::GetChannels(std::uint8_t serverId) {
    std::vector<ChannelData> channels;
    for (const auto& channel : m_channels) {
        if (channel.m_serverId != serverId)
            continue;
        channels.push_back(channel);
    }
    return channels;
}
std::size_t ChannelsInfo::GetChannelsCount(std::uint8_t serverId) {
    return this->GetChannels(serverId).size();
}