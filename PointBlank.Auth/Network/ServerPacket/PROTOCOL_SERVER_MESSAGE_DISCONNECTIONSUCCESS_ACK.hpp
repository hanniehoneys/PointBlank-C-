#pragma once
#include <cstdint>
#include <Network/PacketInterface.hpp>

class PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK : public AckPacketInterface {
public:
    PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK(const uint32_t& flags, const bool& usingHack);
    ~PROTOCOL_SERVER_MESSAGE_DISCONNECTIONSUCCESS_ACK() = default;

    void Build() override;

private:
    std::uint32_t m_flags;
    bool m_bUsingHack;
};