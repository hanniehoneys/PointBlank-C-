#include <Models/Account/Players/PlayerBonus.hpp>

std::uint32_t PlayerBonus::GetSightColor() const {
    return m_sightColor;
}
std::uint32_t PlayerBonus::GetMuzzle() const {
    return m_muzzle;
}
std::uint32_t PlayerBonus::GetFakeRank() const {
    return m_fakeRank;
}
std::string PlayerBonus::GetFakeNick() const {
    return m_fakeNick;
}
std::uint32_t PlayerBonus::GetFreePass() const {
    return m_freePass;
}