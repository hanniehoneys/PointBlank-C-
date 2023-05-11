#include <Network/ClientPacket/PROTOCOL_BASE_GET_USER_INFO_REQ.hpp>
#include <Logger.hpp>
#include <Utilities/Utils.hpp>
#include <Network/ServerPacket/ServerPackets.hpp>
#include <AuthClient.hpp>

PROTOCOL_BASE_GET_USER_INFO_REQ::PROTOCOL_BASE_GET_USER_INFO_REQ(AuthClient* client, const std::vector<uint8_t>& buffer) 
: ReqPacketInterface(client, buffer) {
    //
}

void PROTOCOL_BASE_GET_USER_INFO_REQ::Run() {
    auto* pAccount = m_pClient->GetAccount();
    if (!pAccount || pAccount->GetInventory()->GetItemsCount() != 0)
        return;

    pAccount->LoadInventory();
    /*//havn't implemented yet
        pAccount->LoadMissionList(); 
        pAccount->DiscountPlayerItems();
    */

    m_pClient->SendPacket(PROTOCOL_BASE_GET_USER_INFO_ACK(pAccount));
}