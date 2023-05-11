#include <Models/Account/AccountStatus.hpp>
#include <Database/Database.hpp>
#include <Database/Interface/AccountInterface.hpp>

void AccountStatus::ResetData(const std::uint64_t& userId) {
    if (userId == 0L)
        return;
    auto channelId  =   this->m_channelId;
    auto roomId     =   this->m_roomId;
    auto clanId     =   this->m_clanId;
    auto serverId   =   this->m_serverId;
    this->SetData(UINT32_MAX, userId);
    if (channelId == m_channelId && roomId == m_roomId && clanId == m_clanId && serverId == m_serverId)
        return;
    
    AccountDB accountData{};
    (*GetDatabase()->GetConnection())(update(accountData).set(
        accountData.status = static_cast<std::uint64_t>(UINT32_MAX)
    ).where(accountData.Id == m_userId));
}
void AccountStatus::SetData(const std::uint32_t& data, const std::uint64_t& userId) {
    this->SetData(reinterpret_cast<const uint8_t*>(&data), userId);
}
void AccountStatus::SetData(const uint8_t* buffer, const std::uint64_t& userId) {
    m_userId = userId;
    std::copy(buffer, buffer + 4, m_buffer.begin());
    this->m_channelId   = buffer[0];
    this->m_roomId      = buffer[1];
    this->m_serverId    = buffer[2];
    this->m_clanId      = buffer[3];
}

void AccountStatus::UpdateChannel(const std::uint8_t& channelId) {
    m_channelId = channelId;
    m_buffer[0] = channelId;
    this->UpdateDatabase();
}
void AccountStatus::UpdateRoom(const std::uint8_t& roomId) {
    m_roomId = roomId;
    m_buffer[1] = roomId;
    this->UpdateDatabase();
}
void AccountStatus::UpdateServer(const std::uint8_t& serverId) {
    m_serverId = serverId;
    m_buffer[2] = serverId;
    this->UpdateDatabase();
}
void AccountStatus::UpdateClan(const std::uint8_t& clanId) {
    m_clanId = clanId;
    m_buffer[3] = clanId;
    this->UpdateDatabase();
}

void AccountStatus::UpdateDatabase() {
    std::uint32_t bufferResult = 0;
    for (size_t i = 0; i < m_buffer.size(); ++i)
        bufferResult |= static_cast<uint32_t>(m_buffer[i]) << (i * 8);

    AccountDB accountData{};
    (*GetDatabase()->GetConnection())(update(accountData).set(
        accountData.status = static_cast<std::uint64_t>(bufferResult)
    ).where(accountData.Id == m_userId));
}