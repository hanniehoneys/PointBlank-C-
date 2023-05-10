#include <Utilities/Utils.hpp>
#include <Logger.hpp>

std::string GetFormatTime(time_point time, const std::string& format) {
    auto localtime = system_clock::to_time_t(time);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&localtime), format.c_str());
    return ss.str();
}
std::string ByteArrayToHexString(const std::vector<uint8_t>& buffer) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (size_t i = 0; i < buffer.size(); ++i) {
        ss << std::setw(2) << static_cast<unsigned>(buffer.data()[i]);
        if (i != buffer.size() - 1)
            ss << " ";
    }
    return ss.str();
}

namespace Item {
    std::uint32_t GetItemCategory(const std::uint32_t& itemId) {
        auto staticId = Item::GetIDStatics(itemId, 1);
        int divided = staticId % 10000;
        if (staticId >= 1 && staticId <= 5)
            return 1;
        if (staticId >= 6 && staticId <= 8 || staticId == 15 || staticId >= 26 && staticId <= 27 || divided >= 7 && divided <= 14)
            return 2;
        if (staticId >= 16 && staticId <= 20)
            return 3;
        Logger::PrintBad("Parsing Invalid Category for Item [Id: {}, CategoryType: {}]", itemId, staticId);
        return 0;
    }
    std::uint32_t GetIDStatics(const std::uint32_t& itemId, const std::uint8_t& type) {
        switch (type) {
        case 1: return itemId / 100000;
        case 2: return itemId % 100000 / 1000;
        case 3: return itemId % 1000;
        case 4: return itemId % 10000000 / 100000;
        default:
            return 0;
        }
    }
}