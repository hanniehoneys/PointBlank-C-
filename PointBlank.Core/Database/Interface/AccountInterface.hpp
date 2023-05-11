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
    struct NameColor {
        struct _alias_t {
            static constexpr const char _literal[] = "NameColor";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T nameColor;
                T& operator()() { return nameColor; }
                const T& operator()() const { return nameColor; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
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
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
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
    struct Fights {
        struct _alias_t {
            static constexpr const char _literal[] = "Fights";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T fights;
                T& operator()() { return fights; }
                const T& operator()() const { return fights; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct FightsWin {
        struct _alias_t {
            static constexpr const char _literal[] = "FightsWin";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T fightsWin;
                T& operator()() { return fightsWin; }
                const T& operator()() const { return fightsWin; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct FightsLost {
        struct _alias_t {
            static constexpr const char _literal[] = "FightsLost";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T fightsLost;
                T& operator()() { return fightsLost; }
                const T& operator()() const { return fightsLost; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct FightsDraw {
        struct _alias_t {
            static constexpr const char _literal[] = "FightsDraw";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T fightsDraw;
                T& operator()() { return fightsDraw; }
                const T& operator()() const { return fightsDraw; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct KillsCount {
        struct _alias_t {
            static constexpr const char _literal[] = "KillsCount";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T killsCount;
                T& operator()() { return killsCount; }
                const T& operator()() const { return killsCount; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct DeathsCount {
        struct _alias_t {
            static constexpr const char _literal[] = "DeathsCount";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T deathsCount;
                T& operator()() { return deathsCount; }
                const T& operator()() const { return deathsCount; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct HeadshotsCount {
        struct _alias_t {
            static constexpr const char _literal[] = "HeadshotsCount";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T headshotsCount;
                T& operator()() { return headshotsCount; }
                const T& operator()() const { return headshotsCount; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct EscapesCount {
        struct _alias_t {
            static constexpr const char _literal[] = "EscapesCount";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T escapesCount;
                T& operator()() { return escapesCount; }
                const T& operator()() const { return escapesCount; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct AssistsCount {
        struct _alias_t {
            static constexpr const char _literal[] = "AssistsCount";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T assistsCount;
                T& operator()() { return assistsCount; }
                const T& operator()() const { return assistsCount; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct TotalKillsCount {
        struct _alias_t {
            static constexpr const char _literal[] = "TotalKillsCount";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T totalKillsCount;
                T& operator()() { return totalKillsCount; }
                const T& operator()() const { return totalKillsCount; }
            };
        };
        using _traits = ::sqlpp::make_traits<::sqlpp::integer>;
    };
    struct TotalFightsCount {
        struct _alias_t {
            static constexpr const char _literal[] = "TotalFightsCount";
            using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
            template <typename T>
            struct _member_t {
                T totalFightsCount;
                T& operator()() { return totalFightsCount; }
                const T& operator()() const { return totalFightsCount; }
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
    PlayerInterface::NameColor,
    PlayerInterface::RankID,
    PlayerInterface::Point,
    PlayerInterface::Cash,
    PlayerInterface::Fights,
    PlayerInterface::FightsWin,
    PlayerInterface::FightsLost,
    PlayerInterface::FightsDraw,
    PlayerInterface::KillsCount,
    PlayerInterface::DeathsCount,
    PlayerInterface::HeadshotsCount,
    PlayerInterface::EscapesCount,
    PlayerInterface::AssistsCount,
    PlayerInterface::TotalKillsCount,
    PlayerInterface::TotalFightsCount,
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