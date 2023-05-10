#pragma once
#include <memory>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/mysql/mysql.h>

class Database {
public:
    bool Connect();

    sqlpp::mysql::connection* GetConnection();

public:
    Database() = default;
    ~Database() = default;

private:
    std::unique_ptr<sqlpp::mysql::connection> m_pConnection = NULL;
};

Database* GetDatabase();