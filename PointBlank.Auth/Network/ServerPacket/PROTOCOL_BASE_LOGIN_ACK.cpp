#include <Network/ServerPacket/PROTOCOL_BASE_LOGIN_ACK.hpp>
#include <Core.hpp>
#include <Protocol/Acknowledge.hpp>

PROTOCOL_BASE_LOGIN_ACK::PROTOCOL_BASE_LOGIN_ACK(const eEventResult& result, const std::string& username, const std::uint64_t& userId) 
: AckPacketInterface(eProtocolPacketAck::BASE_LOGIN_ACK, 30 + (username.length() * 2)) {
    m_result = result;
    m_username = username;
    m_userId = userId;
}

void PROTOCOL_BASE_LOGIN_ACK::Build() {
    std::vector<char> usernameArray(m_username.begin(), m_username.end());

    Write(std::vector<uint8_t>(15));
    if (m_result == eEventResult::SUCCESS) {
        Write<std::uint8_t>(m_username.length());
        Write<char>(usernameArray.data(), usernameArray.size());
        Write<std::uint8_t>(0);
        Write<std::uint8_t>(m_username.length());
        Write<char>(usernameArray.data(), usernameArray.size());
        Write<std::uint64_t>(m_userId);
    } else {
        Write<std::uint8_t>(0);
        Write<std::uint8_t>(0);
        Write<std::uint8_t>(0);
        Write<std::uint64_t>(0L);
    }
    Write<std::uint32_t>(static_cast<uint32_t>(m_result));
}