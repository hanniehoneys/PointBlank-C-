#include <Data/MissionsInfo.hpp>
#include <sqlpp11/sqlpp11.h>
#include <Database/Database.hpp>
#include <Database/Interface/MissionsInfoInterface.hpp>

MissionsInfo g_missionsInfo;
MissionsInfo* GetMissionsInfo() {
    return &g_missionsInfo;
}

void MissionsInfo::Load() {
    MissionsInfoDB missionsInfo{};
    for (const auto &row : (*GetDatabase()->GetConnection())(select(all_of(missionsInfo)).from(missionsInfo).where(
        missionsInfo.missionId != 0
    ).order_by(missionsInfo.missionId.asc()))) {
        MissionData mission {
            .m_id = static_cast<std::uint32_t>(row.missionId),
            .m_price = static_cast<std::uint32_t>(row.price)
        };
        if (row.enable) {
            std::uint32_t missionBit = (1U << mission.m_id);
            std::int32_t pageNumber = static_cast<int32_t>(std::ceil(static_cast<double>(mission.m_id) / 32.0));
            if (pageNumber == 1)
                m_pages[0] += missionBit;
            else if (pageNumber == 2)
                m_pages[1] += missionBit;
        }
        m_data.push_back(std::move(mission));
    }
}

std::uint32_t MissionsInfo::GetPageBits(std::uint8_t page) {
    if (page < 0 || page > 1)
        return 0;
    return m_pages[page];
}