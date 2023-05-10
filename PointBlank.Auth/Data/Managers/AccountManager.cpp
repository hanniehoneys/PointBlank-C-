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
            pAccount->SetPoint(row.point);
            pAccount->SetCash(row.cash);
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