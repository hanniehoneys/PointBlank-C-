#pragma once
#include <cstdint>
#include <string>

struct Character {
    std::uint64_t m_objectId;
    std::uint32_t m_slot;
    std::uint32_t m_id;
    std::uint32_t m_createDate;
    std::uint32_t m_playTime;
    std::string m_name;
};