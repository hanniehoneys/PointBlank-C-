#pragma once
#include <string>
#include <Models/Account/Players/PlayerInfo.hpp>

class Friend {
public:
    Friend(const std::uint64_t& userId) 
    : m_userId(userId), m_info(userId) {
        //
    }
    Friend(const std::uint64_t& userId, std::uint32_t rank, std::uint32_t nameColor, std::string name, bool isOnline, AccountStatus status) 
    : m_userId(userId), m_info(userId, rank, nameColor, name, isOnline, status) {
        //
    }

public:
    std::uint64_t GetUserID() const { return m_userId; }
    void SetUserID(const std::uint64_t& userId) { m_userId = userId; }
    std::uint32_t GetState() const { return m_state; }
    void SetState(const std::uint32_t& state) { m_state = state; }
    bool IsRemoved() const { return m_removed; }
    void SetRemoved(const bool& state) { m_removed = state; }

private:
    std::uint64_t m_userId;
    std::uint32_t m_state;
    bool m_removed;
    PlayerInfo m_info;

};