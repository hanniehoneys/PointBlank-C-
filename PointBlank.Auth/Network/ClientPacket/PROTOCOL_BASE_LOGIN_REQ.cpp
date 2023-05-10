#include <Network/ClientPacket/PROTOCOL_BASE_LOGIN_REQ.hpp>
#include <magic_enum.hpp>
#include <Logger.hpp>
#include <Utilities/Utils.hpp>
#include <Data/Configs/AuthConfig.hpp>
#include <Data/Managers/AccountManager.hpp>
#include <AuthClient.hpp>
#include <Network/ServerPacket/ServerPackets.hpp>
#include <Models/Enums/EventResult.hpp>

PROTOCOL_BASE_LOGIN_REQ::PROTOCOL_BASE_LOGIN_REQ(AuthClient* client, const std::vector<uint8_t>& buffer) 
: ReqPacketInterface(client, buffer) {
    ReadBytes(Read<uint8_t>());
    ReadBytes(16);
    ReadString(32);
    ReadBytes(26);

    m_clientLocale = Read<eClientLocale>();
    m_clientVersion = std::to_string(Read<uint8_t>()) + "." + std::to_string(Read<uint16_t>());
    m_tokenLength = Read<uint16_t>();
    m_token = ReadString(m_tokenLength);

    auto TF = Read<uint8_t>();
    auto ISTHIS = Read<uint16_t>();

    m_publicIp = client->GetIPAddress();
    /*
    this.GameLocale = ClientLocale.Thai;
    this.MacAddress = new PhysicalAddress(new byte[6]);
    */
    //""
}

void PROTOCOL_BASE_LOGIN_REQ::Run() {
    if (!GetConfig()->IsGameLocaleAvailable(m_clientLocale) || m_tokenLength < 32) {
        std::string logMessage = std::format("[{}] ", m_token);
        if (!GetConfig()->IsGameLocaleAvailable(m_clientLocale))
            logMessage.append(std::format("Was attempting to connect on client with locale {}", magic_enum::enum_name<eClientLocale>(m_clientLocale)));
        else if (m_tokenLength < 32)
            logMessage.append(std::format("Has invalid token length with size of {}", m_tokenLength));

        m_pClient->SendPacket(PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK(2147483904u, false));
        //Logger::LogLogin(logMessage);
        m_pClient->Close(1000, true);
        return;
    }

    if (!GetAccountManager()->GetAccount(m_token, m_pClient->GetAccount())) { //invalid account
        Logger::Print("Invalid Account");
        m_pClient->SendPacket(PROTOCOL_BASE_LOGIN_ACK(eEventResult::LOGIN_INVALID_ACCOUNT, "", 0L));
        m_pClient->Close(1000, false);
        return;
    } else {
        auto* pAccount = m_pClient->GetAccount(); 
        if (IsDebug()) {
            Logger::Print("User {}({}) is logging on... {}", pAccount->GetUsername(), pAccount->GetUserID(), GetFormatTime(system_clock::now(), "%S:%M:%H %Y-%m-%d"));
            Logger::Print(" > Username: {} | > Password: {}", pAccount->GetUsername(), pAccount->GetPassword());
            Logger::Print(" > Token: {}", m_token);
            Logger::Print(" > Version: {}", m_clientVersion);
        }

        if (pAccount->IsOnline()) {
            /*
            this._client.SendPacket((SendPacket) new PROTOCOL_BASE_LOGIN_ACK(EventErrorEnum.LOGIN_ALREADY_LOGIN_WEB, "", 0L));
                  Logger.LogLogin("Online account [" + player.login + "]");
                  if (account != null && account._connection != null)
                  {
                    account.SendPacket((SendPacket) new PROTOCOL_AUTH_ACCOUNT_KICK_ACK(1));
                    account.SendPacket((SendPacket) new PROTOCOL_SERVER_MESSAGE_ERROR_ACK(2147487744U));
                    account.Close(1000);
                  }
                  else
                    AuthSync.SendLoginKickInfo(player);
                  this._client.Close(1000, false);
            */
            return;
        }    
        pAccount->SetClient(m_pClient);  
        m_pClient->SendPacket(PROTOCOL_BASE_LOGIN_ACK(eEventResult::SUCCESS, pAccount->GetUsername(), pAccount->GetUserID()));
        //m_pClient->SendPacket(std::make_shared<PROTOCOL_AUTH_GET_POINT_CASH_ACK>(eEventResult::SUCCESS, pAccount->GetPoint(), pAccount->GetCash()));
        /*
        pAccount->m_client = = this.client 
        player.SetPlayerId(player.player_id, 31);
        player._clanPlayers = ClanManager.getClanPlayers(player.clan_id, player.player_id);
        ====this._client.SendPacket((SendPacket) new PROTOCOL_BASE_LOGIN_ACK(0, player.login, player.player_id));
        ====this._client.SendPacket((SendPacket) new PROTOCOL_AUTH_GET_POINT_CASH_ACK(0, player._gp, player._money));
        if (player.clan_id > 0)
            this._client.SendPacket((SendPacket) new PROTOCOL_CS_MEMBER_INFO_ACK(player._clanPlayers));
        player._status.SetData(uint.MaxValue, player.player_id);
        player._status.updateServer((byte) 0);
        player.setOnlineStatus(true);
        SendRefresh.RefreshAccount(player, true);
        */
    }
    //m_pClient->SetPlayerData() //m_pPlayer
}