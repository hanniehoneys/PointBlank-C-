#include <Managers/PlayerManager.hpp>
#include <Database/Database.hpp>
#include <Database/Interface/PlayerBonusInterface.hpp>
#include <Database/Interface/PlayerItemsInterface.hpp>
#include <Database/Interface/FriendsInterface.hpp>

PlayerManager g_playerManager;
PlayerManager* GetPlayerManager() {
    return &g_playerManager;
}

PlayerBonus PlayerManager::GetPlayerBonus(const std::uint64_t& userId) {
    PlayerBonus playerBonus = PlayerBonus();
    if (userId == 0L)
        return playerBonus;

    PlayerBonusDB bonusData{};
    for (const auto &row : (*GetDatabase()->GetConnection())(select(all_of(bonusData)).from(bonusData).where(
        bonusData.ownerId == userId
    ))) {
        playerBonus.SetOwnerID(static_cast<std::uint64_t>(row.ownerId));
        playerBonus.SetFlags(static_cast<std::uint64_t>(row.flags));
        playerBonus.SetSightColor(static_cast<std::uint32_t>(row.sightColor));
        playerBonus.SetFreePass(static_cast<std::uint32_t>(row.freePass));
        playerBonus.SetFakeRank(static_cast<std::uint32_t>(row.fakeRank));
        playerBonus.SetFakeNick(row.fakeNick);
        playerBonus.SetMuzzle(static_cast<std::uint32_t>(row.muzzle));
    }

    return playerBonus;
}
std::vector<ItemData> PlayerManager::GetInventoryItems(const std::uint64_t& userId) {
    std::vector<ItemData> items;
    if (userId == 0L)
        return items;

    PlayerItemsDB playerItems{};
    for (const auto &row : (*GetDatabase()->GetConnection())(select(all_of(playerItems)).from(playerItems).where(
        playerItems.ownerId == userId
    ).order_by(playerItems.objectId.asc()))) {
        ItemData item(row.itemId, row.category, row.itemName, row.count, row.objectId);
        items.push_back(std::move(item));
    }

    return items;
}
std::vector<Friend> PlayerManager::GetFriendList(const std::uint64_t& userId) {
    std::vector<Friend> friends;
    if (userId == 0L)
        return friends;

    FriendsDB friendsData{};
    for (const auto &row : (*GetDatabase()->GetConnection())(select(all_of(friendsData)).from(friendsData).where(
        friendsData.ownerId == userId
    ).order_by(friendsData.friendId.asc()))) {
        Friend friendInfo(row.friendId);
        friendInfo.SetState(row.state);
        friendInfo.SetRemoved(row.removed);
        friends.push_back(std::move(friendInfo));
    }

    return friends;
}