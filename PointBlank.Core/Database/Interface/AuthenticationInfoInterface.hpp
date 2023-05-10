#pragma once
#include <cstdint>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace AuthenticationInfoInterface {
    struct ConfigID {
        struct _alias_t {
            static constexpr const char _literal[] = "ConfigID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T configId;
                T& operator()() { return configId; }
                const T& operator()() const { return configId; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integral, ::sqlpp::tag::must_not_insert, ::sqlpp::tag::must_not_update>;
    };
    struct ExitURL {
        struct _alias_t {
            static constexpr const char _literal[] = "ExitURL";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T exitUrl;
                T& operator()() { return exitUrl; }
                const T& operator()() const { return exitUrl; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar, ::sqlpp::tag::must_not_update>;
    };
    struct ChatColor {
        struct _alias_t {
            static constexpr const char _literal[] = "ChatColor";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T chatColor;
                T& operator()() { return chatColor; }
                const T& operator()() const { return chatColor; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct AnnounceColor {
        struct _alias_t {
            static constexpr const char _literal[] = "AnnounceColor";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T announceColor;
                T& operator()() { return announceColor; }
                const T& operator()() const { return announceColor; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct ChatMessage {
        struct _alias_t {
            static constexpr const char _literal[] = "ChatMessage";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T chatMessage;
                T& operator()() { return chatMessage; }
                const T& operator()() const { return chatMessage; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar, ::sqlpp::tag::must_not_update>;
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
    struct WebsiteURL {
        struct _alias_t {
            static constexpr const char _literal[] = "WebsiteURL";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T websiteUrl;
                T& operator()() { return websiteUrl; }
                const T& operator()() const { return websiteUrl; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar, ::sqlpp::tag::must_not_update>;
    };
    struct CommunityURL {
        struct _alias_t {
            static constexpr const char _literal[] = "CommunityURL";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T communityUrl;
                T& operator()() { return communityUrl; }
                const T& operator()() const { return communityUrl; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar, ::sqlpp::tag::must_not_update>;
    };
}

struct AuthenticationInfoDB 
: sqlpp::table_t<AuthenticationInfoDB, 
    AuthenticationInfoInterface::ConfigID, 
    AuthenticationInfoInterface::ExitURL, 
    AuthenticationInfoInterface::ChatColor, 
    AuthenticationInfoInterface::AnnounceColor, 
    AuthenticationInfoInterface::ChatMessage,
    AuthenticationInfoInterface::AnnounceMessage,
    AuthenticationInfoInterface::WebsiteURL,
    AuthenticationInfoInterface::CommunityURL> {
    struct _alias_t {
        static constexpr const char _literal[] = "info_authentication";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T authInfoDB;
            T& operator()() { return authInfoDB; }
            const T& operator()() const { return authInfoDB; }
        };
    };
};