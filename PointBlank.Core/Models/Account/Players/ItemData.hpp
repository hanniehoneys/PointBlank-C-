#pragma once
#include <cstdint>
#include <string>
#include <Utilities/Utils.hpp>

class ItemData {
public:
    ItemData DeepCopy() {
        return *this;
    }

    ItemData()
    : m_id(0), m_category(0), m_equip(0), m_objectId(0), m_count(0) {
    }

    ItemData(std::uint32_t id)
    : m_id(id), m_objectId(0), m_count(0) {
        this->SetItemID(id);
    }

    ItemData(std::uint32_t id, std::string name, std::uint32_t equip, std::uint64_t count, std::uint64_t objId = 0)
    : m_id(id), m_equip(equip), m_name(name), m_objectId(objId), m_count(count) {
    }

    ItemData(std::uint32_t id, std::uint32_t category, std::string name, std::uint32_t equip, std::uint64_t count, std::uint64_t objId = 0)
    : m_id(id), m_category(category), m_equip(equip), m_name(name), m_objectId(objId), m_count(count) {
    }

    ItemData(const ItemData& item)
    : m_id(item.m_id), m_category(item.m_category), m_equip(item.m_equip), m_name(item.m_name), m_objectId(item.m_objectId), m_count(item.m_count) {
    }

private:
    void SetItemID(std::uint32_t id) {
        m_id = id;
        m_category = Item::GetItemCategory(id);
    }

public:
    std::uint32_t m_id;
    std::uint32_t m_category;
    std::uint32_t m_equip;
    std::string m_name;
    std::uint64_t m_objectId;
    std::uint64_t m_count;
};