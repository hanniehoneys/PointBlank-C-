#include <Data/Configs/AuthConfig.hpp>
#include <magic_enum.hpp>

AuthConfig g_config;
AuthConfig* GetConfig() {
    return &g_config;
}

std::uint8_t AuthConfig::GetID() const {
    return m_configId;
}
std::uint8_t AuthConfig::GetServerID() const {
    return m_serverId;
}
std::string AuthConfig::GetIpAddress() const {
    return m_ipAddress;
}
std::uint16_t AuthConfig::GetPort() const {
    return m_port;
}

bool AuthConfig::IsGameLocaleAvailable(eClientLocale locale) {
    return std::find(m_clientLocales.begin(), m_clientLocales.end(), locale) != m_clientLocales.end();
}

bool AuthConfig::Load() {
    try {
        rapidjson::Document document;
        ConfigFile::Parse("Config/Auth.json", &document);

        m_configId = document["ConfigID"].GetUint();
        m_serverId = document["ServerID"].GetUint();
        m_ipAddress = document["IPAddress"].GetString();
        m_port = document["Port"].GetUint();
        //????
        m_syncPort = document["SyncPort"].GetUint();
        Config::Debug = document["Debug"].GetBool();

        if (document.HasMember("ClientLocales") && document["ClientLocales"].IsArray()) {
            const rapidjson::Value& locales = document["ClientLocales"];
            for (auto index = 0; index < locales.Size(); ++index) {
                if (!locales[index].IsString())
                    continue;
                std::optional<eClientLocale> clientOpt = magic_enum::enum_cast<eClientLocale>(locales[index].GetString());
                if (clientOpt.has_value())
                    m_clientLocales.push_back(clientOpt.value());
            }
        }

        if (document.HasMember("Database") && document["Database"].IsObject()) {
            using namespace Config::Database;
            const rapidjson::Value& dbArray = document["Database"];
            Name = dbArray["Name"].GetString();
            Host = dbArray["Host"].GetString();
            User = dbArray["User"].GetString();
            Pass = dbArray["Pass"].GetString();
            Port = dbArray["Port"].GetInt();
        }
        return true;
    }
    catch (std::exception& e) { return false; }
    catch (...) { return false; }
}