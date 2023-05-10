#include <Database/Database.hpp>
#include <sqlpp11/mysql/connection.h>
#include <Core.hpp>
#include <Logger.hpp>

Database g_database;
Database* GetDatabase() {
    return &g_database;
}

bool Database::Connect() {
    try {
        sqlpp::mysql::global_library_init();

        auto pConfig = std::make_shared<sqlpp::mysql::connection_config>();
        pConfig->database            = Config::Database::Name;
        pConfig->host                = Config::Database::Host;
        pConfig->user                = Config::Database::User;
        pConfig->password            = Config::Database::Pass;
        pConfig->port                = Config::Database::Port;
        pConfig->auto_reconnect      = true;
        pConfig->debug               = false;

        m_pConnection = std::make_unique<sqlpp::mysql::connection>(pConfig);
        
        Logger::Print("Initialized Database, connected to MySQL server. [{} | {}]", Config::Database::User, Config::Database::Name);
        return true;
    }
    catch (const sqlpp::exception &e)   { return false; }
    catch (...)                         { return false; }
    return false;
}

sqlpp::mysql::connection* Database::GetConnection() {
    return m_pConnection.get();
}