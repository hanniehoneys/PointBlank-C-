#pragma once
#include <vector>
#include <Models/Account/Players/PlayerBonus.hpp>
#include <Models/Account/Players/ItemData.hpp>
#include <Models/Account/Friend.hpp>

class PlayerManager {
public:
    PlayerManager() = default;
    ~PlayerManager() = default;

public:
    PlayerBonus GetPlayerBonus(const std::uint64_t& userId);
    std::vector<ItemData> GetInventoryItems(const std::uint64_t& userId);
    std::vector<Friend> GetFriendList(const std::uint64_t& userId);
};

PlayerManager* GetPlayerManager();