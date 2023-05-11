#include <Models/Account/Players/PlayerInfo.hpp>

PlayerInfo::PlayerInfo(const std::uint64_t& userId) : m_userId(userId) {
    m_status = AccountStatus();
}
PlayerInfo::PlayerInfo(const std::uint64_t& userId, std::uint32_t rank, std::uint32_t nameColor, std::string name, bool isOnline, AccountStatus status) : m_userId(userId) {
    this->SetInfo(rank, nameColor, name, isOnline, status);
}

void PlayerInfo::SetOnlineStatus(bool state) {
    /*
    if (this._isOnline == state || !ComDiv.updateDB("accounts", "online", (object) state, "player_id", (object) this.player_id))
        return;
    this._isOnline = state;
    */
}
void PlayerInfo::SetInfo(std::uint32_t rank, std::uint32_t nameColor, std::string name, bool isOnline, AccountStatus status) {
    m_rank = rank;
    m_nameColor = nameColor;
    m_name = name;
    m_bIsOnline = isOnline;
    m_status = status;
}