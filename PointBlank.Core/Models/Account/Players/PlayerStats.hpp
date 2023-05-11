#pragma once
#include <cmath>

class PlayerStats
{
public:
    std::uint32_t GetKDRatio() {
        if (m_headshotsCount <= 0 && m_killsCount <= 0)
            return 0;
        return static_cast<uint32_t>(std::floor(static_cast<double>(m_killsCount * 100) + 0.5) / (m_killsCount + m_deathsCount));
    }
    std::uint32_t GetHSRatio() {
        if (m_killsCount <= 0)
            return 0;
        return static_cast<uint32_t>(std::floor(static_cast<double>(m_headshotsCount * 100) / m_killsCount + 0.5));
    }
    
public:
    std::int32_t m_fights;
    std::int32_t m_fightsWin;
    std::int32_t m_fightsLost;
    std::int32_t m_fightsDraw;
    std::int32_t m_killsCount;
    std::int32_t m_deathsCount;
    std::int32_t m_headshotsCount;
    std::int32_t m_escapesCount;
    std::int32_t m_assistsCount;
    std::int32_t m_totalKillsCount;
    std::int32_t m_totalFightsCount;
    std::int32_t m_clanMatches;
    std::int32_t m_clanWins;
    std::int32_t m_clanLoses;
};






