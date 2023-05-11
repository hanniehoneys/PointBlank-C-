#include <Data/Managers/AccountManager.hpp>
#include <mutex>
#include <Database/Interface/AccountInterface.hpp>

std::mutex g_accountsMutex;

AccountManager g_accountManager;
AccountManager* GetAccountManager() {
    return &g_accountManager;
}

void AccountManager::Setup(sqlpp::mysql::connection* pConnection) {
    m_pConnection = pConnection;
}

bool AccountManager::AddAccount(Account* pAccount) {
    std::lock_guard<std::mutex> lock(g_accountsMutex);

    auto result = m_accounts.emplace(pAccount->GetUserID(), pAccount);
    return result.second;
}
bool AccountManager::GetAccount(const std::string& token, Account* pAccount) {
    try {
        AccountDB accountData{};
        for (const auto &row : (*m_pConnection)(select(all_of(accountData)).from(accountData).where(
            accountData.token == token
        ).limit(1u))) {
            if (!row._is_valid)
                continue;
            pAccount->SetUserID(static_cast<uint64_t>(row.Id));
            pAccount->SetUsername(row.username);
            pAccount->SetPassword(row.password);
            pAccount->SetDisplayName(row.displayName);
            pAccount->SetNameColor(row.nameColor);
            pAccount->SetRankID(row.rankId);
            pAccount->SetPoint(row.point);
            pAccount->SetCash(row.cash);

            pAccount->m_statistic.m_fights = static_cast<std::int32_t>(row.fights);
            pAccount->m_statistic.m_fightsWin = static_cast<std::int32_t>(row.fightsWin);
            pAccount->m_statistic.m_fightsLost = static_cast<std::int32_t>(row.fightsLost);
            pAccount->m_statistic.m_fightsDraw = static_cast<std::int32_t>(row.fightsDraw);
            pAccount->m_statistic.m_killsCount = static_cast<std::int32_t>(row.killsCount);
            pAccount->m_statistic.m_deathsCount = static_cast<std::int32_t>(row.deathsCount);
            pAccount->m_statistic.m_headshotsCount = static_cast<std::int32_t>(row.headshotsCount);
            pAccount->m_statistic.m_escapesCount = static_cast<std::int32_t>(row.escapesCount);
            pAccount->m_statistic.m_assistsCount = static_cast<std::int32_t>(row.assistsCount);
            pAccount->m_statistic.m_totalKillsCount = static_cast<std::int32_t>(row.totalKillsCount);
            pAccount->m_statistic.m_totalFightsCount = static_cast<std::int32_t>(row.totalFightsCount);

            pAccount->m_status.SetData(row.status, pAccount->GetUserID());
            pAccount->SetToken(row.token);
            /*
            if (this.AddAccount(acc) && acc._isOnline)
              acc.setOnlineStatus(false);
            */
            return true;
        }
        return false;
    }
    catch(const std::exception &e) {
        return false;
    }
    return false;
}