#pragma once
#include <cstdint>
#include <vector>
#include <Network/PacketInterface.hpp>
#include <Models/Enums/ClientLocale.hpp>

class PROTOCOL_BASE_LOGIN_REQ : public ReqPacketInterface {
public:
    PROTOCOL_BASE_LOGIN_REQ(AuthClient* client, const std::vector<uint8_t>& buffer);
    ~PROTOCOL_BASE_LOGIN_REQ() = default;

    void Run() override;

private:
    eClientLocale m_clientLocale;
    std::string m_clientVersion;
    std::uint16_t m_tokenLength;
    std::string m_token;

    std::string m_publicIp;
};