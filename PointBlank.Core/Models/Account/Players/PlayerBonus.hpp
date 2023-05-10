#pragma once
#include <string>

class PlayerBonus {
public:
    PlayerBonus() : m_sightColor(4), m_muzzle(0), m_fakeRank(55), m_fakeNick("") {
        //
    }

    bool AddBonuses(std::uint32_t itemId) {
        const auto& flags = m_flags;
        const auto& freePass = m_freePass;
        switch (itemId) {
            case 1600001: this->Increase(1); break;
            case 1600002: this->Increase(2); break;
            case 1600003: this->Increase(4); break;
            case 1600004: this->Increase(32); break;
            case 1600011: this->m_freePass = 1; break;
            case 1600037: this->Increase(8); break;
            case 1600038: this->Increase(128); break;
            case 1600119: this->Increase(64); break;
        }
        return m_flags != flags || m_freePass != freePass;
    }
    bool RemoveBonuses(std::uint32_t itemId) {
        const auto& flags = m_flags;
        const auto& freePass = m_freePass;
        switch (itemId) {
            case 1600001: this->Decrease(1); break;
            case 1600002: this->Decrease(2); break;
            case 1600003: this->Decrease(4); break;
            case 1600004: this->Decrease(32); break;
            case 1600011: this->m_freePass = 0; break;
            case 1600037: this->Decrease(8); break;
            case 1600038: this->Decrease(128); break;
            case 1600119: this->Decrease(64); break;
        }
        return m_flags != flags || m_freePass != freePass;
    }

private:
    void Increase(const std::int32_t& value) {
        m_flags |= value;
    }
    void Decrease(const std::int32_t& value) {
        m_flags &= ~value;
    }

public:
    void SetOwnerID(const std::uint64_t& ownerId) { m_ownerId = ownerId; }
    void SetFlags(const std::uint64_t& flags) { m_flags = flags; }
    void SetSightColor(const std::uint32_t& sightColor) { m_sightColor = sightColor; }
    void SetMuzzle(const std::uint32_t& muzzle) { m_muzzle = muzzle; }
    void SetFakeRank(const std::uint32_t& fakeRank) { m_fakeRank = fakeRank; }
    void SetFakeNick(const std::string& fakeNick) { m_fakeNick = fakeNick; }
    void SetFreePass(const std::uint32_t& freePass) { m_freePass = freePass; }

private:
    std::uint64_t m_ownerId;
    std::uint32_t m_flags;
    std::uint32_t m_sightColor;
    std::uint32_t m_muzzle;
    std::uint32_t m_fakeRank;
    std::string m_fakeNick;
    std::uint32_t m_freePass;
};