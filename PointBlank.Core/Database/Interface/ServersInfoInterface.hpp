#pragma once
#include <cstdint>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace ServersInfoInterface {
    struct ID {
        struct _alias_t {
            static constexpr const char _literal[] = "ID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T id;
                T& operator()() { return id; }
                const T& operator()() const { return id; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integral, ::sqlpp::tag::must_not_insert, ::sqlpp::tag::must_not_update>;
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
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct Type {
        struct _alias_t {
            static constexpr const char _literal[] = "Type";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T type;
                T& operator()() { return type; }
                const T& operator()() const { return type; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };   
    struct IPAddress {
        struct _alias_t {
            static constexpr const char _literal[] = "IPAddress";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T ipAddress;
                T& operator()() { return ipAddress; }
                const T& operator()() const { return ipAddress; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar, ::sqlpp::tag::must_not_update>;
    };
    struct Port {
        struct _alias_t {
            static constexpr const char _literal[] = "Port";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T port;
                T& operator()() { return port; }
                const T& operator()() const { return port; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct SyncPort {
        struct _alias_t {
            static constexpr const char _literal[] = "SyncPort";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T syncPort;
                T& operator()() { return syncPort; }
                const T& operator()() const { return syncPort; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct MaxPlayers {
        struct _alias_t {
            static constexpr const char _literal[] = "MaxPlayers";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T maxPlayers;
                T& operator()() { return maxPlayers; }
                const T& operator()() const { return maxPlayers; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
}

struct ServersInfoDB
: sqlpp::table_t<ServersInfoDB, 
    ServersInfoInterface::ID, 
    ServersInfoInterface::State, 
    ServersInfoInterface::Type,
    ServersInfoInterface::IPAddress,
    ServersInfoInterface::Port,
    ServersInfoInterface::SyncPort,
    ServersInfoInterface::MaxPlayers> {
    struct _alias_t {
        static constexpr const char _literal[] = "info_servers";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T serversInfoDB;
            T& operator()() { return serversInfoDB; }
            const T& operator()() const { return serversInfoDB; }
        };
    };
};