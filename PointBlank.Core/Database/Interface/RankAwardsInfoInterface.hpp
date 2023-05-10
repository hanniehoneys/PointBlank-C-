#pragma once
#include <cstdint>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace RankAwardsInfoInterface {
    struct RankID {
        struct _alias_t {
            static constexpr const char _literal[] = "RankID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T rankId;
                T& operator()() { return rankId; }
                const T& operator()() const { return rankId; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_insert, ::sqlpp::tag::must_not_update>;
    };
    struct ItemID {
        struct _alias_t {
            static constexpr const char _literal[] = "ItemID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T itemId;
                T& operator()() { return itemId; }
                const T& operator()() const { return itemId; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct ItemName {
        struct _alias_t {
            static constexpr const char _literal[] = "ItemName";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T itemName;
                T& operator()() { return itemName; }
                const T& operator()() const { return itemName; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar, ::sqlpp::tag::must_not_update>;
    };
    struct ItemCount {
        struct _alias_t {
            static constexpr const char _literal[] = "ItemCount";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T itemCount;
                T& operator()() { return itemCount; }
                const T& operator()() const { return itemCount; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint, ::sqlpp::tag::must_not_update>;
    };
    struct ItemEquip {
        struct _alias_t {
            static constexpr const char _literal[] = "ItemEquip";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T itemEquip;
                T& operator()() { return itemEquip; }
                const T& operator()() const { return itemEquip; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
}

struct RankAwardsInfoDB
: sqlpp::table_t<RankAwardsInfoDB, 
    RankAwardsInfoInterface::RankID, 
    RankAwardsInfoInterface::ItemID, 
    RankAwardsInfoInterface::ItemName,
    RankAwardsInfoInterface::ItemCount,
    RankAwardsInfoInterface::ItemEquip> {
    struct _alias_t {
        static constexpr const char _literal[] = "info_rank_awards";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T rankAwardsInfoDB;
            T& operator()() { return rankAwardsInfoDB; }
            const T& operator()() const { return rankAwardsInfoDB; }
        };
    };
};