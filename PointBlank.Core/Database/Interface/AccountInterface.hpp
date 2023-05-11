#pragma once
#include <cstdint>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace PlayerInterface {
    struct ID {
        struct _alias_t {
            static constexpr const char _literal[] = "ID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T Id;
                T& operator()() { return Id; }
                const T& operator()() const { return Id; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integral, ::sqlpp::tag::must_not_insert, ::sqlpp::tag::must_not_update>;
    };
    struct Username {
        struct _alias_t {
            static constexpr const char _literal[] = "Username";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T username;
                T& operator()() { return username; }
                const T& operator()() const { return username; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar, ::sqlpp::tag::must_not_update>;
    };
    struct Password {
        struct _alias_t {
            static constexpr const char _literal[] = "Password";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T password;
                T& operator()() { return password; }
                const T& operator()() const { return password; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar>;
    };
    struct DisplayName {
        struct _alias_t {
            static constexpr const char _literal[] = "DisplayName";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T displayName;
                T& operator()() { return displayName; }
                const T& operator()() const { return displayName; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar>;
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
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
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
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct Status {
        struct _alias_t {
            static constexpr const char _literal[] = "Status";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T status;
                T& operator()() { return status; }
                const T& operator()() const { return status; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint>;
    };
    struct Token {
        struct _alias_t {
            static constexpr const char _literal[] = "Token";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T token;
                T& operator()() { return token; }
                const T& operator()() const { return token; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar>;
    };
}

struct AccountDB 
: sqlpp::table_t<AccountDB, 
    PlayerInterface::ID, 
    PlayerInterface::Username, 
    PlayerInterface::Password, 
    PlayerInterface::DisplayName, 
    PlayerInterface::Point,
    PlayerInterface::Cash,
    PlayerInterface::Status,
    PlayerInterface::Token> {
    struct _alias_t {
        static constexpr const char _literal[] = "accounts";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T accountDB;
            T& operator()() { return accountDB; }
            const T& operator()() const { return accountDB; }
        };
    };
};