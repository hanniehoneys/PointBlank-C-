#pragma once
#include <chrono>
#include <iomanip>
#include <sstream>
#include <Core.hpp>

std::string GetFormatTime(time_point time, const std::string& format);
std::string ByteArrayToHexString(const std::vector<uint8_t>& buffer);

namespace Item {
    std::uint32_t GetItemCategory(const std::uint32_t& itemId);
    std::uint32_t GetIDStatics(const std::uint32_t& itemId, const std::uint8_t& type);
};