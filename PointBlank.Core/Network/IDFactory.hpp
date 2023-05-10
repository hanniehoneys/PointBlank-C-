#pragma once
#include <cstdint>
#include <bitset>
#include <limits>

class IDFactory {
public:
    IDFactory() = default;
    ~IDFactory() = default;

public:
    int32_t NextID();
    uint16_t NextSeed();

private:
    std::bitset<65536> m_idList;
    std::bitset<65536> m_seedList;
    int m_nextMinID = 0;
    int m_nextMinSeed = 1;
};

IDFactory* GetIDFactory();