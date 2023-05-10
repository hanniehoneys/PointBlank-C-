#pragma once
#include <vector>
#include <Network/PacketInterface.hpp>

class Account;
class Clan;

class PROTOCOL_BASE_GET_USER_INFO_ACK : public AckPacketInterface {
public:
    PROTOCOL_BASE_GET_USER_INFO_ACK(Account* pAccount);
    ~PROTOCOL_BASE_GET_USER_INFO_ACK() = default;
    
private:
    std::size_t GetMemoryUsage();

private:
    Account* m_pAccount;
    Clan* m_pClan;
};