#pragma once
#include <cstdint>
#include <memory>
#include <Logger.hpp>
#include <Protocol/Acknowledge.hpp>
#include <Network/BinaryWriter.hpp>
#include <Network/BinaryReader.hpp>

#define MP(packet, ...) std::make_shared<packet>(##__VA_ARGS__)

class AuthClient;

class AckPacketInterface : public BinaryWriter {
public:
    AckPacketInterface() : BinaryWriter() {
        //
    }
    AckPacketInterface(eProtocolPacketAck packet, std::size_t size) : BinaryWriter(size), m_packet(packet) {
        //
    }
    virtual ~AckPacketInterface() {
        //
    }

    virtual void Build() = 0;

    eProtocolPacketAck GetOperationCode() const {
        return m_packet;
    }

private:
    eProtocolPacketAck m_packet;
};


class ReqPacketInterface : public BinaryReader {
public:
    ReqPacketInterface(AuthClient* client, std::vector<uint8_t> buffer) : BinaryReader(buffer, 4), m_pClient(client) {
        //
    }
    virtual ~ReqPacketInterface() {
        //
    }

    virtual void Run() = 0;

public:
    AuthClient* m_pClient;
};