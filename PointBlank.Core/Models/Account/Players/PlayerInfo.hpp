#pragma once
#include <string>
#include <Models/Account/AccountStatus.hpp>

class PlayerInfo {
public:
    PlayerInfo(const std::uint64_t& userId);
    PlayerInfo(const std::uint64_t& userId, std::uint32_t rank, std::uint32_t nameColor, std::string name, bool isOnline, AccountStatus status);

    void SetOnlineStatus(bool state);
    void SetInfo(std::uint32_t rank, std::uint32_t nameColor, std::string name, bool isOnline, AccountStatus status);

private:
    std::uint64_t m_userId;
    std::uint32_t m_rank;
    std::uint32_t m_nameColor;
    std::string m_name;
    bool m_bIsOnline;
    AccountStatus m_status;
};