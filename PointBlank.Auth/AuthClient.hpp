#pragma once
#include <cstdint>
#include <boost/asio.hpp>
#include <Core.hpp>
#include <Data/Model/Account.hpp>
#include <Network/PacketInterface.hpp>

using boost::asio::ip::address;
using boost::asio::ip::tcp;

class AuthClient : public std::enable_shared_from_this<AuthClient> {
public:
    AuthClient(tcp::socket socket);
    ~AuthClient();

    void Start();
    void Close(int32_t delayMS, bool destroyConnection);

public:
    std::string GetIPAddress();
    address GetAddress();

    uint32_t GetSessionID() const { return m_sessionId; }
    void SetSessionID(const uint32_t& id);
    uint16_t GetSessionSeed() const { return m_sessionSeed; }
    void SetSessionSeed(const uint32_t& seed);

    Account* GetAccount();
    
public:
    void SendPacket(std::shared_ptr<AckPacketInterface> packet);
    void HandlePacket(const std::vector<uint8_t>& buffer);

private:
    void Read();

private:
    tcp::socket m_socket;
    time_point m_connectDate;
    uint32_t m_sessionId;
    uint16_t m_sessionSeed;
    int32_t m_shift;
    int32_t m_firstPacketId;
    std::vector<uint8_t> m_lastBuffer;

    bool m_bClosed;

    std::shared_ptr<Account> m_pAccount;
};