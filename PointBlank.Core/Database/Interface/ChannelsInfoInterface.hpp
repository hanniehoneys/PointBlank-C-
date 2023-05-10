#pragma once
#include <cstdint>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace ChannelsInfoInterface {
    struct ChannelID {
        struct _alias_t {
            static constexpr const char _literal[] = "ChannelID";
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
    struct ServerID {
        struct _alias_t {
            static constexpr const char _literal[] = "ServerID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T serverId;
                T& operator()() { return serverId; }
                const T& operator()() const { return serverId; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };   
    struct AnnounceMessage {
        struct _alias_t {
            static constexpr const char _literal[] = "AnnounceMessage";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T announceMessage;
                T& operator()() { return announceMessage; }
                const T& operator()() const { return announceMessage; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar, ::sqlpp::tag::must_not_update>;
    };
    struct Online {
        struct _alias_t {
            static constexpr const char _literal[] = "Online";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T online;
                T& operator()() { return online; }
                const T& operator()() const { return online; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
}

struct ChannelsInfoDB
: sqlpp::table_t<ChannelsInfoDB, 
    ChannelsInfoInterface::ChannelID, 
    ChannelsInfoInterface::Type,
    ChannelsInfoInterface::ServerID, 
    ChannelsInfoInterface::AnnounceMessage,
    ChannelsInfoInterface::Online> {
    struct _alias_t {
        static constexpr const char _literal[] = "info_channels";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T channelsInfoDB;
            T& operator()() { return channelsInfoDB; }
            const T& operator()() const { return channelsInfoDB; }
        };
    };
};