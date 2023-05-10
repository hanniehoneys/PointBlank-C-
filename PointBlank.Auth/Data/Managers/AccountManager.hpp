#pragma once
#include <unordered_map>
#include <cstdint>
#include <memory>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/mysql/mysql.h>
#include <Data/Model/Account.hpp>

class AccountManager {
public:
    AccountManager() = default;
    ~AccountManager() = default;

    void Setup(sqlpp::mysql::connection* pConnection);

public:
    bool AddAccount(Account* pAccount);
    bool GetAccount(const std::string& token, Account* pAccount);

private:
    sqlpp::mysql::connection* m_pConnection = NULL;
    std::unordered_map<uint64_t, Account*> m_accounts = {};
};

AccountManager* GetAccountManager();