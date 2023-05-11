#pragma once
#include <cstdint>
#include <array>

class AccountStatus {
public:
    void ResetData(const std::uint64_t& userId);
    void SetData(const std::uint32_t& data, const std::uint64_t& userId);
    void SetData(const uint8_t* buffer, const std::uint64_t& userId);

public:
    void UpdateChannel(const std::uint8_t& channelId);
    void UpdateRoom(const std::uint8_t& roomId);
    void UpdateServer(const std::uint8_t& serverId);
    void UpdateClan(const std::uint8_t& clanId);
    
    void UpdateDatabase();

private:
    std::array<uint8_t, 4> m_buffer;
    std::uint64_t m_userId;
    std::uint8_t m_channelId;
    std::uint8_t m_roomId;
    std::uint8_t m_clanId;
    std::uint8_t m_serverId;
};