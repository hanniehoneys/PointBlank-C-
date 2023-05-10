#pragma once
#include <cstdint>
#include <string>
#include <Network/PacketInterface.hpp>
#include <Models/Enums/EventResult.hpp>

class PROTOCOL_BASE_LOGIN_ACK : public AckPacketInterface {
public:
    PROTOCOL_BASE_LOGIN_ACK(const eEventResult& result, const std::string& username, const std::uint64_t& userId);
    ~PROTOCOL_BASE_LOGIN_ACK() = default;

    void Build() override;

private:
    eEventResult m_result;
    std::string m_username;
    std::uint64_t m_userId;
};