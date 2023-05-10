#pragma once
#include <cstdint>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace PlayerTitlesInterface {
    struct OwnerID {
        struct _alias_t {
            static constexpr const char _literal[] = "OwnerID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T ownerId;
                T& operator()() { return ownerId; }
                const T& operator()() const { return ownerId ; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint, ::sqlpp::tag::must_not_update>;
    };
    struct EquipedSlot1 {
        struct _alias_t {
            static constexpr const char _literal[] = "EquipedSlot1";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T equipedSlot1;
                T& operator()() { return equipedSlot1; }
                const T& operator()() const { return equipedSlot1; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct EquipedSlot2 {
        struct _alias_t {
            static constexpr const char _literal[] = "EquipedSlot2";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T equipedSlot2;
                T& operator()() { return equipedSlot2; }
                const T& operator()() const { return equipedSlot2; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct EquipedSlot3 {
        struct _alias_t {
            static constexpr const char _literal[] = "EquipedSlot3";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T equipedSlot3;
                T& operator()() { return equipedSlot3; }
                const T& operator()() const { return equipedSlot3; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct Flags {
        struct _alias_t {
            static constexpr const char _literal[] = "Flags";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T flags;
                T& operator()() { return flags; }
                const T& operator()() const { return flags; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct AvailableSlots {
        struct _alias_t {
            static constexpr const char _literal[] = "AvailableSlots";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T availableSlots;
                T& operator()() { return availableSlots; }
                const T& operator()() const { return availableSlots; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
}

struct PlayerTitlesDB 
: sqlpp::table_t<PlayerTitlesDB, 
    PlayerTitlesInterface::OwnerID, 
    PlayerTitlesInterface::EquipedSlot1, 
    PlayerTitlesInterface::EquipedSlot2,
    PlayerTitlesInterface::EquipedSlot3, 
    PlayerTitlesInterface::Flags, 
    PlayerTitlesInterface::AvailableSlots> {
    struct _alias_t {
        static constexpr const char _literal[] = "player_titles";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T playerTitlesDB;
            T& operator()() { return playerTitlesDB; }
            const T& operator()() const { return playerTitlesDB; }
        };
    };
};