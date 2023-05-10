#pragma once
#include <vector>
#include <Models/Account/Players/ItemData.hpp>

class PlayerInventory {
public:
    ItemData* GetItem(std::uint32_t itemId) {
        for (auto& item : m_items) {
            if (item.GetID() != itemId)
                continue;
            return &item;
        }
        return NULL;
    }
    std::vector<ItemData*> GetItemsByType(std::uint32_t type) {
        std::vector<ItemData*> items;
        
        for (auto& item : m_items) {
            if (!(item.GetCategory() == type || item.GetID() > 1600000 && item.GetID() < 1700000 && type == 4))
                continue;
            items.push_back(&item);
        }
        return items;
    }
    void RemoveItem(std::uint64_t objectId) {
        for (auto index = 0; index < m_items.size(); ++index) {
            if (m_items[index].GetObjectID() != objectId)
                continue;
            m_items.erase(m_items.begin() + index);
            break;
        }
    }

    void LoadBasicItems() {
        //havn't implemented yet
    }

public:
    bool AddItem(ItemData item) {
        m_items.push_back(item);
    }
    bool RemoveItem(ItemData* item) {
        for (auto index = 0; index < m_items.size(); ++index) {
            if (&m_items[index] != item)
                continue;
            m_items.erase(m_items.begin() + index);
            return true;
        }
        return false;
    }
    std::size_t GetItemsCount() {
        return m_items.size();
    }

public:
    std::vector<ItemData> m_items = std::vector<ItemData>();
};