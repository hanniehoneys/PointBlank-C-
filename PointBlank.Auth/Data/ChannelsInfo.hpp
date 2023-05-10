#pragma once
#include <cstdint>
#include <string>
#include <vector>

struct ChannelData {
    std::uint32_t m_id;
    std::uint32_t m_type;
    std::uint32_t m_serverId;
    std::string m_announceMessage;
    std::uint32_t m_players;
};

class ChannelsInfo {
public:
    ChannelsInfo() = default;
    ~ChannelsInfo() = default;

    void Load(std::uint8_t serverId);

public:
    std::vector<ChannelData> GetChannels();
    std::vector<ChannelData> GetChannels(std::uint8_t serverId);
    std::size_t GetChannelsCount(std::uint8_t serverId);

private:
    std::vector<ChannelData> m_channels;
};

ChannelsInfo* GetChannelsInfo();