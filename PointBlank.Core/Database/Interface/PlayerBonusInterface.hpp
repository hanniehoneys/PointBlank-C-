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
    struct SightColor {
        struct _alias_t {
            static constexpr const char _literal[] = "SightColor";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T sightColor;
                T& operator()() { return sightColor; }
                const T& operator()() const { return sightColor; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct FreePass {
        struct _alias_t {
            static constexpr const char _literal[] = "FreePass";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T freePass;
                T& operator()() { return freePass; }
                const T& operator()() const { return freePass; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct FakeRank {
        struct _alias_t {
            static constexpr const char _literal[] = "FakeRank";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T fakeRank;
                T& operator()() { return fakeRank; }
                const T& operator()() const { return fakeRank; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct FakeNick {
        struct _alias_t {
            static constexpr const char _literal[] = "FakeNick";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T fakeNick;
                T& operator()() { return fakeNick; }
                const T& operator()() const { return fakeNick; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar>;
    };
    struct Muzzle {
        struct _alias_t {
            static constexpr const char _literal[] = "Muzzle";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T muzzle;
                T& operator()() { return muzzle; }
                const T& operator()() const { return muzzle; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
}

struct PlayerBonusDB 
: sqlpp::table_t<PlayerBonusDB, 
    PlayerTitlesInterface::OwnerID, 
    PlayerTitlesInterface::Flags, 
    PlayerTitlesInterface::SightColor,
    PlayerTitlesInterface::FreePass, 
    PlayerTitlesInterface::FakeRank, 
    PlayerTitlesInterface::FakeNick,
    PlayerTitlesInterface::Muzzle> {
    struct _alias_t {
        static constexpr const char _literal[] = "player_bonus";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T playerBonusDB;
            T& operator()() { return playerBonusDB; }
            const T& operator()() const { return playerBonusDB; }
        };
    };
};