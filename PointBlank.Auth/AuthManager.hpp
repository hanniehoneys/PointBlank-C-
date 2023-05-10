#pragma once
#include <iostream>
#include <memory>
#include <thread>
#include <map>
#include <atomic>
#include <boost/asio.hpp>
#include <Data/Configs/AuthConfig.hpp>

using boost::asio::ip::tcp;

class ServerConfig;
class AuthClient;

class AuthManager
{
public:
    AuthManager() = default;
    ~AuthManager() = default;
    /*static std::map<uint32_t, std::shared_ptr<AuthClient>> _socketList;
    static std::vector<std::shared_ptr<AuthClient>> _loginQueue;
    static ServerConfig Config;
    static bool ServerIsClosed;*/

    bool Start();

    void AddSocket(std::shared_ptr<AuthClient> pClient);
    bool RemoveSocket(std::shared_ptr<AuthClient> pClient);

    std::size_t GetTotalClients() const { return m_socketList.size(); }

    ServerConfig* GetServerConfig() const { return m_pServerConfig.get(); }

private:
    void DoAccept(tcp::acceptor& acceptor);

private:
    std::map<uint32_t, std::shared_ptr<AuthClient>> m_socketList;
    std::shared_ptr<ServerConfig> m_pServerConfig;
};

AuthManager* GetAuthManager();