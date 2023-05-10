#pragma once
#include <cstdint>
#include <array>
#include <unordered_map>
#include <Models/Account/Players/ItemData.hpp>

struct GoodItem {
public:
    std::uint32_t m_id;
    ItemData m_item = ItemData(0, "", 0, 0, 0);
    std::array<uint32_t, 2> m_price;
    std::array<uint32_t, 3> m_buyType;
    std::uint32_t m_tag;
    std::uint32_t m_title;
    std::uint32_t m_visibility;
};

struct ItemRepair {
public:
    std::uint32_t m_itemId;
    std::array<uint32_t, 2> m_price;
    std::uint32_t m_quantityp;
    bool m_enable;
};

class ShopManager {
public:
    ShopManager() = default;
    ~ShopManager() = default;

    void Load(std::uint8_t type);

public:
    GoodItem* GetItem(std::uint32_t itemId);

private:
    std::vector<GoodItem> m_items;
    std::vector<GoodItem> m_buyableList;
    std::unordered_map<std::uint32_t, GoodItem> m_uniqueList;
};

ShopManager* GetShopManager();