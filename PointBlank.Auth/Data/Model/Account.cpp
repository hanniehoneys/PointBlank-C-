#include <Data/Model/Account.hpp>

void Account::SetUserID(const std::uint64_t& userId) {
    m_userId = userId;
}
void Account::SetUsername(const std::string& username) {
    m_username = username;
}
void Account::SetPassword(const std::string& password) {
    m_password = password;
}
void Account::SetDisplayName(const std::string& displayName) {
    m_displayName = displayName;
}
void Account::SetPoint(const std::int32_t& point) {
    m_point = point;
}
void Account::SetCash(const std::int32_t& cash) {
    m_cash = cash;
}
void Account::SetToken(const std::string& token) {
    m_token = token;
}