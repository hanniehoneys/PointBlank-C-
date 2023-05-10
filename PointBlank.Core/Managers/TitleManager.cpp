#include <Managers/TitleManager.hpp>
#include <Database/Database.hpp>
#include <Database/Interface/PlayerTitlesInterface.hpp>

TitleManager g_titleManager;
TitleManager* GetTitleManager() {
    return &g_titleManager;
}

bool TitleManager::Insert(const std::uint64_t& userId) {
    return false;
}
PlayerTitle TitleManager::Load(const std::uint64_t& userId) {
    PlayerTitle playerTitle{};
    if (userId == 0L)
        return playerTitle;

    PlayerTitlesDB titlesData{};
    for (const auto& row : (*GetDatabase()->GetConnection())(select(all_of(titlesData)).from(titlesData).where(
        titlesData.ownerId == userId
    ).limit(1U))) {
        playerTitle.SetOwnerID(static_cast<std::uint64_t>(row.ownerId));
        playerTitle.SetFlags(static_cast<std::uint64_t>(row.flags));
        playerTitle.SetAvailableSlots(static_cast<std::uint32_t>(row.availableSlots));
        playerTitle.SetEquiped(row.equipedSlot1, row.equipedSlot2, row.equipedSlot3);
    }

    return playerTitle;
}