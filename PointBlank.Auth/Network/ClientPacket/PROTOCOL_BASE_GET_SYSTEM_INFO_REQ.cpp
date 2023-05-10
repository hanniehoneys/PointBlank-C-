#include <Network/ClientPacket/PROTOCOL_BASE_GET_SYSTEM_INFO_REQ.hpp>
#include <Logger.hpp>
#include <Utilities/Utils.hpp>
#include <AuthClient.hpp>
#include <Network/ServerPacket/ServerPackets.hpp>

PROTOCOL_BASE_GET_SYSTEM_INFO_REQ::PROTOCOL_BASE_GET_SYSTEM_INFO_REQ(AuthClient* client, const std::vector<uint8_t>& buffer) 
: ReqPacketInterface(client, buffer) {
    //
}

void PROTOCOL_BASE_GET_SYSTEM_INFO_REQ::Run() {
    m_pClient->SendPacket(std::make_shared<PROTOCOL_BASE_NOTICE_ACK>());
    m_pClient->SendPacket(std::make_shared<PROTOCOL_BASE_URL_LIST_ACK>());
    m_pClient->SendPacket(std::make_shared<PROTOCOL_BASE_BOOSTEVENT_INFO_ACK>());
    m_pClient->SendPacket(std::make_shared<PROTOCOL_BASE_STEPUP_MODE_INFO_ACK>());
    m_pClient->SendPacket(std::make_shared<PROTOCOL_BASE_CHANNELTYPE_CONDITION_ACK>());
    m_pClient->SendPacket(std::make_shared<PROTOCOL_BASE_GET_SYSTEM_INFO_ACK>());
}