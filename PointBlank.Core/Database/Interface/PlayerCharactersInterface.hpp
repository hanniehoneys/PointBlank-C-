#pragma once
#include <cstdint>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace PlayerCharactersInterface {
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
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct Slot {
        struct _alias_t {
            static constexpr const char _literal[] = "Slot";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T slot;
                T& operator()() { return slot; }
                const T& operator()() const { return slot; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint>;
    };
    struct Name {
        struct _alias_t {
            static constexpr const char _literal[] = "Name";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T name;
                T& operator()() { return name; }
                const T& operator()() const { return name; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::varchar>;
    };
    struct CreateDate {
        struct _alias_t {
            static constexpr const char _literal[] = "CreateDate";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T createDate;
                T& operator()() { return createDate; }
                const T& operator()() const { return createDate; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint, ::sqlpp::tag::must_not_update>;
    };
    struct PlayTime {
        struct _alias_t {
            static constexpr const char _literal[] = "PlayTime";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T playTime;
                T& operator()() { return playTime; }
                const T& operator()() const { return playTime; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::bigint, ::sqlpp::tag::must_not_update>;
    };
}

struct PlayerCharactersDB 
: sqlpp::table_t<PlayerCharactersDB, 
    PlayerCharactersInterface::ObjectID, 
    PlayerCharactersInterface::OwnerID, 
    PlayerCharactersInterface::ID, 
    PlayerCharactersInterface::Slot,
    PlayerCharactersInterface::Name, 
    PlayerCharactersInterface::CreateDate, 
    PlayerCharactersInterface::PlayTime> {
    struct _alias_t {
        static constexpr const char _literal[] = "player_characters";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T playerCharactersDB;
            T& operator()() { return playerCharactersDB; }
            const T& operator()() const { return playerCharactersDB; }
        };
    };
};