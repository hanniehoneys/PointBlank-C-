#include <Managers/ShopManager.hpp>
#include <mutex>
#include <Database/Database.hpp>
#include <Database/Interface/ShopInterface.hpp>
#include <Utilities/Utils.hpp>

std::mutex g_itemsMutex;

ShopManager g_shopManager;
ShopManager* GetShopManager() {
    return &g_shopManager;
}

void ShopManager::Load(std::uint8_t type) {
    ShopDB shopData{};
    for (const auto& row : (*GetDatabase()->GetConnection())(select(all_of(shopData)).from(shopData).where(
        shopData.goodId != 0
    ))) {
        GoodItem goodItem {
            .m_id =         static_cast<std::uint32_t>(row.goodId),
            .m_price =      { (uint32_t)row.point, (uint32_t)row.cash },
            .m_buyType =    { (uint32_t)row.buyType, (uint32_t)row.buyType2, (uint32_t)row.buyType3 },
            .m_tag =        static_cast<std::uint32_t>(row.tag),
            .m_title =      static_cast<std::uint32_t>(row.title),
            .m_visibility = static_cast<std::uint32_t>(row.visibility)
        };
        goodItem.m_item.SetID(static_cast<std::uint32_t>(row.itemId));
        goodItem.m_item.SetName(row.itemName);
        goodItem.m_item.SetCount(static_cast<std::uint64_t>(row.count));

        std::uint32_t staticId = Item::GetIDStatics(goodItem.m_item.GetID(), 1);
        bool result;
        switch (type) {
        case 1: result = true; break;
        case 2: result = (staticId == 16 ? true : false); break;
        default: result = false; break;
        }

        if (result) {
            auto& item = m_items.emplace_back(std::move(goodItem)); //maybe `goodItem` as pointer is a good idea? if we have to push this much
            if (item.m_visibility != 2 && item.m_visibility != 4) //make an enum for this instead of constant int
                m_buyableList.push_back(item);
            if (!m_uniqueList.contains(item.m_item.GetID()) && item.m_buyType[0] > 0) {
                m_uniqueList.insert_or_assign(item.m_item.GetID(), item);
            }
        }
    }

    /*
    if (type == 1)
    {
    ShopManager.LoadItemRepair();
    ShopManager.LoadDataMatching1Goods(0);
    ShopManager.LoadDataMatching2(1);
    ShopManager.LoadDataItems();
    ShopManager.LoadDataItemRepairs();
    }
    */
}

GoodItem* ShopManager::GetItem(std::uint32_t itemId) {
    if (itemId == 0)
        return NULL;
    
    std::lock_guard<std::mutex> lock(g_itemsMutex);
    
    for (auto& item : m_items) {
        if (item.m_item.GetID() != itemId)
            continue;
        return &item;
    }
    
    return NULL;
}