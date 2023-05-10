#include <Data/RanksInfo.hpp>
#include <fstream>
#include <format>
#include <mutex>
#include <Database/Database.hpp>
#include <rapidjson/document.h>
#include <ConfigFile.hpp>
#include <Logger.hpp>
#include <Database/Interface/RankAwardsInfoInterface.hpp>

std::mutex g_ranksMutex;

RanksInfo g_ranksInfo;
RanksInfo* GetRanksInfo() {
    return &g_ranksInfo;
}

void RanksInfo::Load() {
    rapidjson::Document document;
    ConfigFile::Parse("Data/Rank/Player.json", &document);

    const rapidjson::Value& ranks = document["Ranks"];
    for (auto index = 0; index < ranks.Size(); index++) {
        const rapidjson::Value& rank = ranks[index];
        RankData rankData(
            rank["ID"].GetInt(),
            rank["NextLevel"].GetInt(),
            rank["PointUp"].GetInt(),
            rank["AllExp"].GetInt()
        );
        m_ranks.push_back(std::move(rankData));
    }
}
void RanksInfo::LoadAwards() {
    RankAwardsInfoDB awardsInfo{};
    for (const auto &row : (*GetDatabase()->GetConnection())(select(all_of(awardsInfo)).from(awardsInfo).where(
        awardsInfo.itemId != 0
    ).order_by(awardsInfo.rankId.asc()))) {
        auto rankId = static_cast<uint32_t>(row.rankId);
        if (rankId < 0 || rankId > m_ranks.size())
            continue;

        ItemData item(
            static_cast<std::uint32_t>(row.itemId),
            row.itemName,
            row.itemEquip,
            row.itemCount
        );
        m_ranks[rankId].m_awards.push_back(std::move(item));
    }
}

std::vector<ItemData> RanksInfo::GetAwards(const std::uint8_t& rankId) {
    std::lock_guard<std::mutex> lock(g_ranksMutex);

    if (rankId < 0 || rankId > m_ranks.size())
        return {};
    return m_ranks[rankId].m_awards;
}
/*public static List<ItemsModel> getAwards(int rank)
    {
      lock (RankXml._awards)
      {
        List<ItemsModel> itemsModelList;
        if (RankXml._awards.TryGetValue(rank, out itemsModelList))
          return itemsModelList;
      }
      return new List<ItemsModel>();
    }*/