#pragma once
#include <vector>
#include <Network/PacketInterface.hpp>

struct ChannelData;

class PROTOCOL_BASE_GET_CHANNELLIST_ACK : public AckPacketInterface {
public:
    PROTOCOL_BASE_GET_CHANNELLIST_ACK(std::vector<ChannelData> channels);
    ~PROTOCOL_BASE_GET_CHANNELLIST_ACK() = default;
    
private:
    std::size_t GetMemoryUsage();

private:
    std::vector<ChannelData> m_channels;
};