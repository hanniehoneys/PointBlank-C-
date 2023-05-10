#pragma once
#include <cstdint>
#include <string>
#include <Network/PacketInterface.hpp>

class PROTOCOL_BASE_URL_LIST_ACK : public AckPacketInterface {
public:
    PROTOCOL_BASE_URL_LIST_ACK();
    ~PROTOCOL_BASE_URL_LIST_ACK() = default;

    void Build() override;

private:

};