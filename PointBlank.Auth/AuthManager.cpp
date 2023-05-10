#include <AuthManager.hpp>
#include <Logger.hpp>
#include <AuthClient.hpp>
#include <Data/Configs/AuthConfig.hpp>
#include <Managers/Server/ServerConfig.hpp>

AuthManager g_authManager;
AuthManager* GetAuthManager() {
    return &g_authManager;
}

bool AuthManager::Start() {
    try {
        m_pServerConfig = ServerConfig::Generate(GetConfig()->GetID());

        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(boost::asio::ip::make_address_v4(GetConfig()->GetIpAddress()), GetConfig()->GetPort()));
        
        acceptor.listen(10);
        DoAccept(acceptor);

        Logger::Print("Server is listening to {}:{}", GetConfig()->GetIpAddress(), GetConfig()->GetPort());
        io_context.run();
        return true;
    }
    catch(boost::system::system_error& e) {
        Logger::PrintBad(e.what());
        return false;
    }
}

void AuthManager::AddSocket(std::shared_ptr<AuthClient> pClient) {
    if (!pClient)
        return;

    uint32_t sessionCounter = 0;
    while (sessionCounter < 100000U) {
        uint32_t sessionId = ++sessionCounter;
        if (!(m_socketList.find(sessionId) == m_socketList.end() && m_socketList.emplace(sessionId, pClient).second))
            continue;
        Logger::Debug("AuthManager: Adding new client to socket list, sessionId: {}, ipAddress: {}", sessionId, pClient->GetIPAddress());

        pClient->SetSessionID(sessionId);
        pClient->Start();
        return;
    }
    pClient->Close(500, true);
}
bool AuthManager::RemoveSocket(std::shared_ptr<AuthClient> pClient) {
    if (!pClient || pClient->GetSessionID() == 0 || !m_socketList.contains(pClient->GetSessionID()))
        return false;
    m_socketList.erase(pClient->GetSessionID());
    return true;
}

void AuthManager::DoAccept(tcp::acceptor& acceptor) {
    acceptor.async_accept([&acceptor, this](const boost::system::error_code& error, tcp::socket socket) {
        if (!error) {
            auto pClient = std::make_shared<AuthClient>(std::move(socket));
            this->AddSocket(pClient);
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        } else {
            Logger::PrintBad("Failed on connection: {}", error.what());
        }

        DoAccept(acceptor);
    });
}