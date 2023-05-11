#pragma once
#include <vector>
#include <Models/Account/Friend.hpp>

class PlayerFriend
{
public:
    void Insert(const Friend& friendObj);
    bool Remove(const Friend& friendObj);
    void Remove(const std::uint64_t& userId);

    std::size_t GetIndex(const std::uint64_t& userId);
    Friend* Get(const std::uint64_t& userId);
    Friend* Get(const std::uint64_t& userId, std::size_t& index);

public:
    std::vector<Friend> m_friends;
};