#include <Managers/CharacterManager.hpp>
#include <Database/Database.hpp>
#include <Database/Interface/PlayerCharactersInterface.hpp>

CharacterManager g_characterManager;
CharacterManager* GetCharacterManager() {
    return &g_characterManager;
}

bool CharacterManager::Insert(const std::uint64_t& userId) {
    return false;
}
std::vector<Character> CharacterManager::Load(const std::uint64_t& userId) {
    std::vector<Character> characters;
    if (userId == 0L)
        return characters;

    PlayerCharactersDB charactersData{};
    for (const auto& row : (*GetDatabase()->GetConnection())(select(all_of(charactersData)).from(charactersData).where(
        charactersData.ownerId == userId
    ).order_by(charactersData.slot.asc()))) {
        Character character{};
        character.m_objectId = row.objectId;
        character.m_id = row.id;
        character.m_slot = static_cast<uint32_t>(row.slot);
        character.m_name = row.name;
        character.m_createDate = row.createDate;
        character.m_playTime = row.playTime;
        characters.push_back(std::move(character));
    }

    return characters;
}