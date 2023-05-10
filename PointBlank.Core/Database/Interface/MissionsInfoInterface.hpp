#pragma once
#include <cstdint>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/table.h>
#include <sqlpp11/char_sequence.h>
#include <sqlpp11/column_types.h>
#include <sqlpp11/select_column_list.h>

namespace MissionsInfoInterface {
    struct MissionID {
        struct _alias_t {
            static constexpr const char _literal[] = "MissionID";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T missionId;
                T& operator()() { return missionId; }
                const T& operator()() const { return missionId; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integral, ::sqlpp::tag::must_not_insert, ::sqlpp::tag::must_not_update>;
    };
    struct Price {
        struct _alias_t {
            static constexpr const char _literal[] = "Price";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T price;
                T& operator()() { return price; }
                const T& operator()() const { return price; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer, ::sqlpp::tag::must_not_update>;
    };
    struct Enable {
        struct _alias_t {
            static constexpr const char _literal[] = "Enable";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T enable;
                T& operator()() { return enable; }
                const T& operator()() const { return enable; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::boolean, ::sqlpp::tag::must_not_update>;
    };
}

struct MissionsInfoDB
: sqlpp::table_t<MissionsInfoDB, 
    MissionsInfoInterface::MissionID, 
    MissionsInfoInterface::Price, 
    MissionsInfoInterface::Enable> {
    struct _alias_t {
        static constexpr const char _literal[] = "info_missions";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template <typename T>
        struct _member_t {
            T missionsInfoDB;
            T& operator()() { return missionsInfoDB; }
            const T& operator()() const { return missionsInfoDB; }
        };
    };
};