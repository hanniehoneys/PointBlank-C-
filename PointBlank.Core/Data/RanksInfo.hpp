#pragma once
#include <cstdint>
#include <vector>
#include <Models/Account/Players/ItemData.hpp>

struct RankData {
public:
    RankData(std::int32_t id, std::int32_t nextLevel, std::int32_t pointUp, std::int32_t allExp)
    : m_id(id), m_nextLevel(nextLevel), m_pointUp(pointUp), m_allExp(allExp) {
        m_awards = std::vector<ItemData>{};
    }

public:
    std::int32_t m_id;
    std::int32_t m_nextLevel;
    std::int32_t m_pointUp;
    std::int32_t m_allExp;
    std::vector<ItemData> m_awards;
};

class RanksInfo {
public:
    RanksInfo() = default;
    ~RanksInfo() = default;

    void Load();
    void LoadAwards();

private:
    std::vector<RankData> m_ranks;
};

RanksInfo* GetRanksInfo();