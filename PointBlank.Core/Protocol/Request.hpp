#pragma once
#include <cstdint>

enum class eProtocolPacketReq : std::uint16_t {
    UNKNOWN_REQ,
    BASE_LOGIN_REQ = 257,
    BASE_GET_SYSTEM_INFO_REQ = 522,
    BASE_GET_USER_INFO_REQ = 524,
    BASE_GET_CHANNELLIST_REQ = 540,
    REQ_MAXVAL
};