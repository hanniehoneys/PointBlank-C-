#pragma once
#include <vector>
#include <Models/Account/Players/Character.hpp>

class CharacterManager {
public:
    CharacterManager() = default;
    ~CharacterManager() = default;

public:
    bool Insert(const std::uint64_t& userId);
    std::vector<Character> Load(const std::uint64_t& userId);
};

CharacterManager* GetCharacterManager();