#pragma once
#include <cstdint>
#include <vector>
#include <Logger.hpp>
#include <Core.hpp>
#include <ConfigFile.hpp>
#include <Models/Enums/ClientLocale.hpp>

class AuthConfig {
public:
    AuthConfig() = default;
    ~AuthConfig() = default;

    bool Load();

public:
    std::uint8_t GetID() const;
    std::uint8_t GetServerID() const;
    std::string GetIpAddress() const;
    std::uint16_t GetPort() const;

    bool IsGameLocaleAvailable(eClientLocale locale);
    
private:
    std::uint8_t m_configId;
    std::uint8_t m_serverId;
    std::string m_ipAddress;
    std::uint16_t m_port;
    //??????
    std::uint16_t m_syncPort;

    std::vector<eClientLocale> m_clientLocales;
};

AuthConfig* GetConfig();