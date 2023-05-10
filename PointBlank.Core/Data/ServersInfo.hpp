#pragma once
#include <cstdint>
#include <array>
#include <vector>
#include <boost/asio.hpp>

using namespace boost::asio::ip;

struct GameServer {
public:
    GameServer(const std::string& ipAddress, const std::uint16_t& syncPort)
    : m_ip(ipAddress), m_syncPort(syncPort), m_endpoint(address::from_string(ipAddress), syncPort) {
        //
    }
    
public:
    std::uint32_t m_id;
    std::uint32_t m_state;
    std::uint32_t m_type;
    std::string m_ip;
    std::uint16_t m_port;
    std::uint16_t m_syncPort;
    std::uint32_t m_maxPlayers;
    std::uint32_t m_lastCount;
    udp::endpoint m_endpoint;
};

class ServersInfo {
public:
    ServersInfo() = default;
    ~ServersInfo() = default;

    void Load();

public:
    std::size_t GetServersCount() const;
    std::vector<GameServer> GetServers();

private:
    std::vector<GameServer> m_servers;
};

ServersInfo* GetServersInfo();