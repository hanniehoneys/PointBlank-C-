#pragma once
#include <cstdint>
#include <string>
#include <memory>
#include <Models/Account/Players/PlayerBonus.hpp>
#include <Models/Account/Players/PlayerInventory.hpp>
#include <Models/Account/Players/Character.hpp>
#include <Models/Account/Title/PlayerTitle.hpp>

class AuthClient;

class Account {
public:
    Account() = default;
    ~Account() = default;

    std::uint64_t GetUserID() const { return m_userId; }
    void SetUserID(const std::uint64_t& userId);
    std::string GetUsername() const { return m_username; }
    void SetUsername(const std::string& username);
    std::string GetPassword() const { return m_password; }
    void SetPassword(const std::string& password);
    std::string GetDisplayName() const { return m_displayName; }
    void SetDisplayName(const std::string& displayName);
    std::int32_t GetPoint() const { return m_point; }
    void SetPoint(const std::int32_t& point);
    std::int32_t GetCash() const { return m_cash; }
    void SetCash(const std::int32_t& cash);
    std::string GetToken() const { return m_token; }
    void SetToken(const std::string& token);

    bool IsOnline() const { return m_bOnline; }
    void SetOnline(const bool& online) { m_bOnline = online; }

    AuthClient* GetClient() { return m_pClient; }
    void SetClient(AuthClient* pClient) { m_pClient = pClient; }

    PlayerInventory* GetInventory() { return m_pInventory.get(); }
    
public:
    void SetPlayerID(std::uint64_t userId, std::uint32_t flags);

    void LoadAccountInfo(std::uint32_t flags);
    void LoadInventory();

private:
    std::uint64_t m_userId;
    std::string m_username;
    std::string m_password;
    std::string m_displayName;
    std::int32_t m_point;
    std::int32_t m_cash;
    std::string m_token;
    bool m_bOnline;
    AuthClient* m_pClient;
    
    PlayerBonus m_bonus;
    PlayerTitle m_title;
    
    std::shared_ptr<PlayerInventory> m_pInventory = std::make_shared<PlayerInventory>();
    
    std::vector<Character> m_characters = {};
};