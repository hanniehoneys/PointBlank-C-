#pragma once
#include <cstdint>
#include <string>
#include <Network/PacketInterface.hpp>

class PROTOCOL_BASE_STEPUP_MODE_INFO_ACK : public AckPacketInterface {
public:
    PROTOCOL_BASE_STEPUP_MODE_INFO_ACK();
    ~PROTOCOL_BASE_STEPUP_MODE_INFO_ACK() = default;

    void Build() override;

private:

};