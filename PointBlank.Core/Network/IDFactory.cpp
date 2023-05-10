#include <Network/IDFactory.hpp>

IDFactory g_idFactory;
IDFactory* GetIDFactory() {
    return &g_idFactory;
}

int32_t IDFactory::NextID() {
    int32_t pos = 0;
    if (this->m_nextMinID != std::numeric_limits<int32_t>::min()) {
        for (int32_t i = this->m_nextMinID; i < this->m_idList.size(); ++i) {
            if (!this->m_idList[i]) {
                pos = i;
                this->m_idList.set(pos);
                this->m_nextMinID = pos + 1;
                return pos;
            }
        }
    }
    return pos;
}

uint16_t IDFactory::NextSeed() {
    uint16_t num = 0;
    if (this->m_nextMinSeed != 0) {
        for (int32_t i = this->m_nextMinSeed; i < this->m_seedList.size(); ++i) {
            if (!this->m_seedList[i]) {
                num = static_cast<uint16_t>(i);
                this->m_seedList.set(num);
                this->m_nextMinSeed = num + 1;
                return num;
            }
        }
    }
    return num;
}