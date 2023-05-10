#include <AuthClient.hpp>
#include <thread>
#include <functional>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <magic_enum.hpp>
#include <AuthManager.hpp>
#include <Logger.hpp>
#include <Protocol/Packet.hpp>
#include <Protocol/Request.hpp>
#include <Network/IDFactory.hpp>
#include <Network/ClientPacket/ClientPackets.hpp>
#include <Network/ServerPacket/ServerPackets.hpp>

using namespace boost::placeholders;

AuthClient::AuthClient(tcp::socket socket) : m_socket(std::move(socket)), m_bClosed(false) {
    m_pAccount = std::make_shared<Account>();
    m_sessionSeed = GetIDFactory()->NextSeed();

    m_socket.set_option(tcp::no_delay(true));
}
AuthClient::~AuthClient() {
    if (!m_bClosed)
        this->Close(0, true);
        
    if (m_pAccount)
        m_pAccount.reset();
}

void AuthClient::Start() {
    this->m_shift = static_cast<int>((this->m_sessionId % 7U) + 1);
    this->m_connectDate = system_clock::now();

    this->SendPacket(PROTOCOL_BASE_CONNECT_ACK(GetSessionSeed(), GetSessionID()));
    std::thread(std::bind(&AuthClient::Read, shared_from_this())).detach();
}
void AuthClient::Close(int32_t delayMS, bool destroyConnection) {
    if (m_bClosed)
        return;
    
    m_bClosed = true;
    Logger::Debug("AuthClient: Closing connection from client {}, sessionId: {}, seed: {}", this->GetIPAddress(), GetSessionID(), GetSessionSeed());

    if (destroyConnection) {
        if (m_pAccount != NULL) {
            /*
            player->setOnlineStatus(false);
            if (player->_status.serverId == 0)
                SendRefresh::RefreshAccount(player, false);
            player->_status.ResetData(player->player_id);
            player->SimpleClear();
            player->updateCacheInfo();
            player = NULL;
            */
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(delayMS));
        boost::system::error_code ec;
        m_socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
        m_socket.close();
    }
    else if (m_pAccount != NULL) {
        /*
        player->SimpleClear();
        player->updateCacheInfo();
        player = NULL;
        */
    }
    //AuthSync::UpdateGSCount(0);

    GetAuthManager()->RemoveSocket(shared_from_this());
}

std::string AuthClient::GetIPAddress() {
    try {
        if (m_socket.is_open() && m_socket.remote_endpoint().address().is_v4()) {
            return m_socket.remote_endpoint().address().to_string();
        }
        return "";
    }
    catch (...) {
        return "";
    }
}
address AuthClient::GetAddress() {
    try {
        if (m_socket.is_open() && m_socket.remote_endpoint().address().is_v4()) {
            return m_socket.remote_endpoint().address();
        }
        return address();
    }
    catch (...) {
        return address();
    }
}

void AuthClient::SetSessionID(const uint32_t& id) {
    m_sessionId = id;
}
void AuthClient::SetSessionSeed(const uint32_t& seed) {
    m_sessionSeed = seed;
}

Account* AuthClient::GetAccount() {
    return m_pAccount.get();
}

void AuthClient::Read() {
    try {
        std::array<uint8_t, 1024> buffer;

        boost::system::error_code error;
        auto bytesRead = m_socket.read_some(boost::asio::buffer(buffer), error);
        if (bytesRead < 4 || bytesRead > 1024) {
            //Logger::Debug("AuthClient: Failure on reading packet from client: {}", error.message());
            this->Close(0, true);
            return;
        }
        
        auto dataLength = (int32_t)(reinterpret_cast<uint16_t*>(buffer.data())[0]) & static_cast<int32_t>(std::numeric_limits<int16_t>::max());
        std::vector<uint8_t> packetData(dataLength + 2);
        std::memcpy(packetData.data(), buffer.data() + 2, packetData.size());

        this->HandlePacket(Packet::Decrypt(packetData, m_shift));

        std::thread(std::bind(&AuthClient::Read, this)).detach();
    }
    catch(std::exception& e) {
        Logger::PrintBad(e.what());
    }
    catch(...) {
        this->Close(0, true);
    }
}

void AuthClient::SendPacket(ISPacket packet) {
    try {
        if (!m_socket.is_open())
            return;
        
        std::vector<uint8_t> bufferArray(packet.m_data);
        if (bufferArray.size() < 2)
            return;

        BinaryWriter packetData(bufferArray.size() + 4);
        packetData.Write<uint16_t>(bufferArray.size());
        packetData.Write<uint16_t>(packet.m_type);
        packetData.Write(bufferArray.data(), bufferArray.size());

        if (packetData.GetSize() > 4) {
            //const boost::system::error_code& error
            auto bytesTransferred = m_socket.write_some(boost::asio::buffer(packetData.GetBuffer()));

            if (IsDebug())
                Logger::Print("[S]: Opcode: {}\tData Length: {}", static_cast<uint16_t>(packet.m_type), packetData.GetSize());
        }
    }
    catch(std::exception& e) {
        Logger::PrintBad("WHAT: {}", e.what());
    }
    catch(...) {
        this->Close(0, true);
    }
}

void AuthClient::HandlePacket(const std::vector<uint8_t>& buffer) {
    if (m_bClosed)
        return;

    eProtocolPacketReq operationCode = *reinterpret_cast<const eProtocolPacketReq*>(buffer.data());  
    if (IsDebug())
        Logger::Print("[C]: Opcode: {}\tData Length: {}", *(std::uint16_t*)buffer.data(), buffer.size() + 2);

    //this->FirstPacketCheck(uint16);
    std::shared_ptr<ReqPacketInterface> requestPacket = NULL;
    switch (operationCode) {
    case eProtocolPacketReq::BASE_LOGIN_REQ:
        requestPacket = std::make_shared<PROTOCOL_BASE_LOGIN_REQ>(this, buffer);
        break;
    case eProtocolPacketReq::BASE_GET_SYSTEM_INFO_REQ:
        requestPacket = std::make_shared<PROTOCOL_BASE_GET_SYSTEM_INFO_REQ>(this, buffer);
        break;
    default:
        Logger::PrintBad("Unhandled Opcode {}", *(std::uint16_t*)buffer.data());
        break;
    }

    if (requestPacket != NULL)
        std::thread(std::bind(&ReqPacketInterface::Run, requestPacket)).detach();
}