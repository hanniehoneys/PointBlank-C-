#pragma once
#include <cstdint>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace FriendsInterface {
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
    struct FriendID {
        struct _alias_t {
            static constexpr const char _literal[] = "FriendID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T friendId;
                T& operator()() { return friendId; }
                const T& operator()() const { return friendId; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint>;
    };
    struct State {
        struct _alias_t {
            static constexpr const char _literal[] = "State";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T state;
                T& operator()() { return state; }
                const T& operator()() const { return state; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct Removed {
        struct _alias_t {
            static constexpr const char _literal[] = "Removed";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T removed;
                T& operator()() { return removed; }
                const T& operator()() const { return removed; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::tinyint>;
    };
}

struct FriendsDB 
: sqlpp::table_t<FriendsDB, 
    FriendsInterface::OwnerID, 
    FriendsInterface::FriendID, 
    FriendsInterface::State,
    FriendsInterface::Removed> {
    struct _alias_t {
        static constexpr const char _literal[] = "friends";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T friendsDB;
            T& operator()() { return friendsDB; }
            const T& operator()() const { return friendsDB; }
        };
    };
};