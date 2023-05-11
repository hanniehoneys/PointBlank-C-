#include <Data/Model/Account.hpp>
#include <Managers/PlayerManager.hpp>
#include <Managers/TitleManager.hpp>
#include <Managers/CharacterManager.hpp>

void Account::SetUserID(const std::uint64_t& userId) {
    m_userId = userId;
}
void Account::SetUsername(const std::string& username) {
    m_username = username;
}
void Account::SetPassword(const std::string& password) {
    m_password = password;
}
void Account::SetDisplayName(const std::string& displayName) {
    m_displayName = displayName;
}
void Account::SetPoint(const std::int32_t& point) {
    m_point = point;
}
void Account::SetCash(const std::int32_t& cash) {
    m_cash = cash;
}
void Account::SetToken(const std::string& token) {
    m_token = token;
}

void Account::SetPlayerID(std::uint64_t userId, std::uint32_t flags) {
    m_userId = userId;
    this->LoadAccountInfo(flags);
}

void Account::LoadAccountInfo(std::uint32_t flags) {
    if (!flags || !m_userId)
        return;
    if ((flags & 1) == 1) {
        m_title = GetTitleManager()->Load(m_userId);
        //m_topups = GetPlayerManager()->GetPlayerTopups(m_userId);
        m_characters = GetCharacterManager()->Load(m_userId);
        /*
        this.Daily = PlayerManager.getPlayerDailyRecord(this.player_id);
        if (this.Daily == null)
            PlayerManager.CreatePlayerDailyRecord(this.player_id);
        */
    }
    if ((flags & 2) == 2)
        m_bonus = GetPlayerManager()->GetPlayerBonus(m_userId);
    if ((flags & 4) == 4) {
        auto list = GetPlayerManager()->GetFriendList(m_userId);
        if (list.size() > 0)
            m_friend.m_friends = list;
    }
    /*
      if ((LoadType & 8) == 8)
      {
        this._event = PlayerManager.getPlayerEventDB(this.player_id);
        if (this._event == null)
        {
          PlayerManager.addEventDB(this.player_id);
          this._event = new PlayerEvent();
        }
      }
      if ((LoadType & 16) != 16)
        return;
      this._config = PlayerManager.getConfigDB(this.player_id);
      if (this._config == null)
        PlayerManager.CreateConfigDB(this.player_id);
      if (this._connection == null)
        return;
      this.ICafe = ICafeManager.GetCafe(this._connection.GetIPAddress());
      if (!this.ICafe)
        return;
      this.pc_cafe = 1;*/
}
void Account::LoadInventory() {
    auto items = GetPlayerManager()->GetInventoryItems(m_userId);
    m_pInventory->m_items.insert(m_pInventory->m_items.end(), items.begin(), items.end());
}