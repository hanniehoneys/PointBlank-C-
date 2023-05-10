#pragma once
#include <cstdint>
#include <vector>
#include <Network/PacketInterface.hpp>

class PROTOCOL_BASE_GET_SYSTEM_INFO_REQ : public ReqPacketInterface {
public:
    PROTOCOL_BASE_GET_SYSTEM_INFO_REQ(AuthClient* client, const std::vector<uint8_t>& buffer);
    ~PROTOCOL_BASE_GET_SYSTEM_INFO_REQ() = default;

    void Run() override;
};