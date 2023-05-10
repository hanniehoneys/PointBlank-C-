#pragma once
#include <cstdint>
#include <array>
#include <vector>

struct MissionData {
    std::uint32_t m_id;
    std::uint32_t m_price;
};

class MissionsInfo {
public:
    MissionsInfo() = default;
    ~MissionsInfo() = default;

    void Load();

public:
    std::uint32_t GetPageBits(std::uint8_t page);

private:
    std::vector<MissionData> m_data;
    std::array<uint32_t, 2> m_pages;
};

MissionsInfo* GetMissionsInfo();