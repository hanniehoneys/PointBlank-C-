#pragma once
#include <cstdint>
#include <string>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/mysql/mysql.h>
#include <Database/Database.hpp>
#include <Database/Interface/AuthenticationInfoInterface.hpp>

class ServerConfig {
public:
    ServerConfig() = default;
    ~ServerConfig() = default;

    static std::shared_ptr<ServerConfig> Generate(std::uint8_t configId) {
        try {
            AuthenticationInfoDB authInfoData{};
            for (const auto &row : (*GetDatabase()->GetConnection())(select(all_of(authInfoData)).from(authInfoData).where(
                authInfoData.configId == configId
            ).limit(1u))) {
                if (!row._is_valid)
                    continue;
                auto pConfig = std::make_shared<ServerConfig>();

                pConfig->m_configId = static_cast<std::uint8_t>(row.configId);
                pConfig->m_exitUrl = row.exitUrl;
                pConfig->m_chatColor = row.chatColor;
                pConfig->m_announceColor = row.announceColor;
                pConfig->m_chatMessage = row.chatMessage;
                pConfig->m_announceMessage = row.announceMessage;
                pConfig->m_websiteUrl = row.websiteUrl;
                pConfig->m_communityUrl = row.communityUrl;
                return pConfig;
            }
            return NULL;
        }
        catch(const std::exception &e) {
            return NULL;
        }
        return NULL;
    }

public:
    std::uint8_t GetConfigID() const { return m_configId; }
    std::string GetExitURL() const { return m_exitUrl; }
    std::uint32_t GetChatColor() const { return m_chatColor; }
    std::uint32_t GetAnnounceColor() const { return m_announceColor; }
    std::string GetChatMessage() const { return m_chatMessage; }
    std::string GetAnnounceMessage() const { return m_announceMessage; }
    std::string GetWebsiteURL() const { return m_websiteUrl; }
    std::string GetCommunityURL() const { return m_communityUrl; }

private:
    std::uint8_t m_configId;
    std::string m_exitUrl;
    std::uint32_t m_chatColor;
    std::uint32_t m_announceColor;
    std::string m_chatMessage;
    std::string m_announceMessage;
    std::string m_websiteUrl;
    std::string m_communityUrl;
};