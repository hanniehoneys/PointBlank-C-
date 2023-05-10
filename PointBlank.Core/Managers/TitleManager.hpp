#pragma once
#include <vector>
#include <Models/Account/Title/PlayerTitle.hpp>

class TitleManager {
public:
    TitleManager() = default;
    ~TitleManager() = default;

public:
    bool Insert(const std::uint64_t& userId);
    PlayerTitle Load(const std::uint64_t& userId);
};

TitleManager* GetTitleManager();