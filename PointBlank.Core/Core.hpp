#pragma once
#include <chrono>
#include <string>

using high_resolution_clock = std::chrono::high_resolution_clock;
using system_clock = std::chrono::system_clock;
using steady_clock = std::chrono::steady_clock;
using time_point =  system_clock::time_point;

namespace Config {
    inline bool Debug;

    namespace Database {
        inline std::string Name;
        inline std::string Host;
        inline std::string User;
        inline std::string Pass;
        inline std::uint16_t Port;
    };
};

bool IsDebug();