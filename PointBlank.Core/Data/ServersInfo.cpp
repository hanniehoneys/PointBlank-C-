#include <Data/ServersInfo.hpp>
#include <sqlpp11/sqlpp11.h>
#include <Database/Database.hpp>
#include <Database/Interface/ServersInfoInterface.hpp>

ServersInfo g_serversInfo;
ServersInfo* GetServersInfo() {
    return &g_serversInfo;
}

void ServersInfo::Load() {
    ServersInfoDB serversInfo{};
    for (const auto &row : (*GetDatabase()->GetConnection())(select(all_of(serversInfo)).from(serversInfo).where(
        serversInfo.id != 0
    ).order_by(serversInfo.id.asc()))) {
        GameServer server(row.ipAddress, row.syncPort);
        server.m_id = static_cast<std::uint32_t>(row.id);
        server.m_state = static_cast<std::uint32_t>(row.state);
        server.m_port = static_cast<std::uint16_t>(row.port);
        server.m_maxPlayers = static_cast<std::uint32_t>(row.maxPlayers);
        m_servers.push_back(std::move(server));
    }
}

std::size_t ServersInfo::GetServersCount() const {
    return m_servers.size();
}
std::vector<GameServer> ServersInfo::GetServers() {
    return m_servers;
}