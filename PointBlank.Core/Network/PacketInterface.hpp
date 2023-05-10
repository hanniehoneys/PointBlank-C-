#pragma once
#include <cstdint>
#include <memory>
#include <Logger.hpp>
#include <Protocol/Acknowledge.hpp>
#include <Network/BinaryWriter.hpp>
#include <Network/BinaryReader.hpp>

class AuthClient;

class IPacketType {
public:
    IPacketType(const std::uint16_t& type) : m_type(type) {
        //
    }

public:
    std::uint16_t m_type;
};

class ISPacket : public IPacketType {
public:
    ISPacket(const std::uint16_t& type) : IPacketType(type) {
        //
    }

public:
    std::vector<uint8_t> m_data;
};

class AckPacketInterface : public ISPacket, public BinaryWriter {
public:
    AckPacketInterface(eProtocolPacketAck packet, std::size_t size) : BinaryWriter(size), ISPacket(static_cast<uint16_t>(packet)) {
        //
    }
    virtual ~AckPacketInterface() {
        //
    }

public:
    void Pack() {
        m_data.resize(BinaryWriter::GetSize());
        std::memcpy(m_data.data(), BinaryWriter::Get(), BinaryWriter::GetSize());
    }
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