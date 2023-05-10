#pragma once
#include <cstdint>
#include <vector>
#include <Network/PacketInterface.hpp>

class PROTOCOL_BASE_GET_CHANNELLIST_REQ : public ReqPacketInterface {
public:
    PROTOCOL_BASE_GET_CHANNELLIST_REQ(AuthClient* client, const std::vector<uint8_t>& buffer);
    ~PROTOCOL_BASE_GET_CHANNELLIST_REQ() = default;

    void Run() override;

private:
    std::uint32_t m_serverId;
};