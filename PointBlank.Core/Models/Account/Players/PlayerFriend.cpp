#include <Models/Account/Players/PlayerFriend.hpp>

void PlayerFriend::Insert(const Friend& friendObj) {
    m_friends.push_back(friendObj);
}
bool PlayerFriend::Remove(const Friend& friendObj) {
    for (auto index = 0; index < m_friends.size(); ++index) {
        if (m_friends[index].GetUserID() != friendObj.GetUserID())
            continue;

        m_friends.erase(m_friends.begin() + index);
        return true;
    }
    return false;
}
void PlayerFriend::Remove(const std::size_t& index) {
    if (index >= 0 && index < m_friends.size())
        m_friends.erase(m_friends.begin() + index);
}
void PlayerFriend::Remove(const std::uint64_t& userId) {
    for (auto index = 0; index < m_friends.size(); ++index) {
        if (m_friends[index].GetUserID() != userId)
            continue;

        m_friends.erase(m_friends.begin() + index);
        break;
    }
}

std::size_t PlayerFriend::GetIndex(const std::uint64_t& userId) {
    for (auto index = 0; index < m_friends.size(); ++index) {
        if (m_friends[index].GetUserID() != userId)
            continue;

        return static_cast<std::size_t>(index);
    }
    return -1;
}
Friend* PlayerFriend::Get(const std::size_t& index) {
    if (index >= 0 && index < m_friends.size())
        return &m_friends[index];
    return NULL;
}
Friend* PlayerFriend::Get(const std::uint64_t& userId) {
    for (auto index = 0; index < m_friends.size(); ++index) {
        if (m_friends[index].GetUserID() != userId)
            continue;

        return &m_friends[index];
    }
    return NULL;
}
Friend* PlayerFriend::Get(const std::uint64_t& userId, std::size_t& index) {
    for (auto i = 0; i < m_friends.size(); ++i) {
        if (m_friends[i].GetUserID() != userId)
            continue; 

        index = static_cast<std::size_t>(i);
        return &m_friends[i];
    }
    index = -1;
    return NULL;
}