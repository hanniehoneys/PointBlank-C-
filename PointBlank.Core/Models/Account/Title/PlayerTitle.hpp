#pragma once
#include <cstdint>
#include <array>

class PlayerTitle {
public:
    std::uint64_t Add(const std::uint64_t& flag) {
        m_flags |= flag;
        return m_flags;
    }
    bool Contains(const std::uint64_t& flag) {
        return (m_flags & flag) == flag || flag == 0L;
    }
    void Equip(const std::uint8_t& slot, const std::uint32_t& value) {
        if (slot < 0 || slot > 2)
            return;
        m_equiped[slot] = value;
    }
    std::uint32_t GetEquiped(const std::uint8_t& slot) {
        if (slot < 0 || slot > 2)
            return 0;
        return m_equiped[slot];
    }

public:
    std::uint64_t GetOwnerID() const { return m_ownerId; }
    void SetOwnerID(const std::uint64_t& ownerId) { m_ownerId = ownerId; }
    std::uint64_t GetFlags() const { return m_flags; }
    void SetFlags(const std::uint64_t& flags) { m_flags = flags; }
    std::uint32_t GetAvailableSlots() const { return m_availableSlots; }
    void SetAvailableSlots(const std::uint32_t& slots) { m_availableSlots = slots; }
    std::uint32_t GetEquiped(const std::uint8_t& index) { return m_equiped[index]; }
    void SetEquiped(std::uint32_t slot1, std::uint32_t slot2, std::uint32_t slot3) { m_equiped = { slot1, slot2, slot3 }; }

private:
    std::uint64_t m_ownerId;
    std::uint64_t m_flags;
    std::uint32_t m_availableSlots = 1;
    std::array<uint32_t, 3> m_equiped;
};