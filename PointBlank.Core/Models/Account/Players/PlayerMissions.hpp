#pragma once
#include <array>

class PlayerMissions {
public:
    PlayerMissions DeepCopy() {
        return *this;
    }

    std::array<uint8_t, 40> GetCurrentMissionList() {
        if (m_currentMission < 0 || m_currentMission > 3)
            return {};
        return m_lists[m_currentMission];
    }

    std::uint32_t GetCard(const std::uint8_t& index) {
        if (index < 0 || index > 3)
            return 0;
        return m_cards[index];
    }
    std::uint32_t GetCurrentCard() {
        return this->GetCard(m_currentMission);
    }

    std::uint32_t GetMission(const std::uint8_t& index) {
        if (index < 0 || index > 3)
            return 0;
        return m_missions[index];
    }
    std::uint32_t GetCurrentMission() {
        return this->GetMission(m_currentMission);
    }
    
    /*void UpdateSelectedCard() {
      if (std::numeric_limits<uint16_t>::max() != ComDiv::getCardFlags(getCurrentMissionId(), getCurrentCard(), getCurrentMissionList())) {
        selectedCard = true;
      }
    }*/
    
private:
    std::uint32_t m_currentMission;
    std::array<std::array<uint8_t, 40>, 4> m_lists;
    std::array<uint32_t, 4> m_cards;
    std::array<uint32_t, 4> m_missions;
    bool m_bSelectedCard;
};