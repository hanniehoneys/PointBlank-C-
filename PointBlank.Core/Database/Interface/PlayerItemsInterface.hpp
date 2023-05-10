#pragma once
#include <cstdint>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace PlayerItemsInterface {
    struct ObjectID {
        struct _alias_t {
            static constexpr const char _literal[] = "ObjectID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T objectId;
                T& operator()() { return objectId; }
                const T& operator()() const { return objectId; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint, ::sqlpp::tag::must_not_insert, ::sqlpp::tag::must_not_update>;
    };
    struct OwnerID {
        struct _alias_t {
            static constexpr const char _literal[] = "OwnerID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T ownerId;
                T& operator()() { return ownerId; }
                const T& operator()() const { return ownerId; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint, ::sqlpp::tag::must_not_update>;
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
    struct Count {
        struct _alias_t {
            static constexpr const char _literal[] = "Count";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T count;
                T& operator()() { return count; }
                const T& operator()() const { return count; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint, ::sqlpp::tag::must_not_update>;
    };
    struct Category {
        struct _alias_t {
            static constexpr const char _literal[] = "Category";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T category;
                T& operator()() { return category; }
                const T& operator()() const { return category; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct Equip {
        struct _alias_t {
            static constexpr const char _literal[] = "Equip";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T equip;
                T& operator()() { return equip; }
                const T& operator()() const { return equip; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
}

struct PlayerItemsDB 
: sqlpp::table_t<PlayerItemsDB, 
    PlayerItemsInterface::ObjectID, 
    PlayerItemsInterface::OwnerID, 
    PlayerItemsInterface::ItemID, 
    PlayerItemsInterface::ItemName,
    PlayerItemsInterface::Count, 
    PlayerItemsInterface::Category, 
    PlayerItemsInterface::Equip> {
    struct _alias_t {
        static constexpr const char _literal[] = "player_items";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T playerItemsDB;
            T& operator()() { return playerItemsDB; }
            const T& operator()() const { return playerItemsDB; }
        };
    };
};