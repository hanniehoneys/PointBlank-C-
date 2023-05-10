#pragma once
#include <cstdint>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace ShopInterface {
    struct GoodID {
        struct _alias_t {
            static constexpr const char _literal[] = "GoodID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T goodId;
                T& operator()() { return goodId; }
                const T& operator()() const { return goodId; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integral, ::sqlpp::tag::must_not_insert, ::sqlpp::tag::must_not_update>;
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
    struct Point {
        struct _alias_t {
            static constexpr const char _literal[] = "Point";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T point;
                T& operator()() { return point; }
                const T& operator()() const { return point; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct Cash {
        struct _alias_t {
            static constexpr const char _literal[] = "Cash";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T cash;
                T& operator()() { return cash; }
                const T& operator()() const { return cash; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
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
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct BuyType {
        struct _alias_t {
            static constexpr const char _literal[] = "BuyType";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T buyType;
                T& operator()() { return buyType; }
                const T& operator()() const { return buyType; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct BuyType2 {
        struct _alias_t {
            static constexpr const char _literal[] = "BuyType2";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T buyType2;
                T& operator()() { return buyType2; }
                const T& operator()() const { return buyType2; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct BuyType3 {
        struct _alias_t {
            static constexpr const char _literal[] = "BuyType3";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T buyType3;
                T& operator()() { return buyType3; }
                const T& operator()() const { return buyType3; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct Tag {
        struct _alias_t {
            static constexpr const char _literal[] = "Tag";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T tag;
                T& operator()() { return tag; }
                const T& operator()() const { return tag; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct Title {
        struct _alias_t {
            static constexpr const char _literal[] = "Title";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T title;
                T& operator()() { return title; }
                const T& operator()() const { return title; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct Visibility {
        struct _alias_t {
            static constexpr const char _literal[] = "Visibility";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T visibility;
                T& operator()() { return visibility; }
                const T& operator()() const { return visibility; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
}

struct ShopDB
: sqlpp::table_t<ShopDB, 
    ShopInterface::GoodID, 
    ShopInterface::ItemID, 
    ShopInterface::ItemName,
    ShopInterface::Point, 
    ShopInterface::Cash, 
    ShopInterface::Count,
    ShopInterface::BuyType,
    ShopInterface::BuyType2, 
    ShopInterface::BuyType3,
    ShopInterface::Tag,
    ShopInterface::Title, 
    ShopInterface::Visibility> {
    struct _alias_t {
        static constexpr const char _literal[] = "shop";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T shopDB;
            T& operator()() { return shopDB; }
            const T& operator()() const { return shopDB; }
        };
    };
};