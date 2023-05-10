#include <Network/ServerPacket/PROTOCOL_BASE_LOGIN_ACK.hpp>
#include <Core.hpp>
#include <Protocol/Acknowledge.hpp>

PROTOCOL_BASE_LOGIN_ACK::PROTOCOL_BASE_LOGIN_ACK(const eEventResult& result, const std::string& username, const std::uint64_t& userId) 
: AckPacketInterface(eProtocolPacketAck::BASE_LOGIN_ACK, 30 + (username.length() * 2)) {
    std::vector<char> usernameArray(username.begin(), username.end());

    Write(std::vector<uint8_t>(15));
    if (result == eEventResult::SUCCESS) {
        Write<std::uint8_t>(username.length());
        Write<char>(usernameArray.data(), usernameArray.size());
        Write<std::uint8_t>(0);
        Write<std::uint8_t>(username.length());
        Write<char>(usernameArray.data(), usernameArray.size());
        Write<std::uint64_t>(userId);
    } else {
        Write<std::uint8_t>(0);
        Write<std::uint8_t>(0);
        Write<std::uint8_t>(0);
        Write<std::uint64_t>(0L);
    }
    Write<std::uint32_t>(static_cast<uint32_t>(result));
    
    AckPacketInterface::Pack();
}