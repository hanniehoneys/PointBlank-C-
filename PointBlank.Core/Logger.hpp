#pragma once
#include <windows.h>
#include <iostream>
#include <string_view>
#include <format>

enum class Color {
    BLACK = 30,
    DARK_RED = 31,
    DARK_GREEN = 32,
    DARK_YELLOW = 33,
    DARK_BLUE = 34,
    DARK_MAGENTA = 35,
    DARK_CYAN = 36,
    RED = 91,
    GREEN = 92,
    YELLOW = 93,
    BLUE = 94,
    MAGENTA = 95,
    CYAN = 96,
    WHITE = 97
};

namespace Logger {
	template <typename... Args>
    void Print(std::string_view text, Args&&... args) noexcept {
		std::cout << std::format("{}\n", std::vformat(text, std::make_format_args(args...)));
	}
    template <typename... Args>
    inline void Debug(std::string_view text, Args&&... args) noexcept {
        std::cout << "[Debug] ";
        Print(std::format("{}", std::vformat(text, std::make_format_args(args...))));
    }
    template <typename... Args>
    inline void PrintGood(std::string_view text, Args&&... args) noexcept {
        std::cout << "[+] ";
        Print(std::format("{}", std::vformat(text, std::make_format_args(args...))));
    }
    template <typename... Args>
    inline void PrintBad(std::string_view text, Args&&... args) noexcept {
        std::cout << "[-] ";
        Print(std::format("{}", std::vformat(text, std::make_format_args(args...))));
    }
}