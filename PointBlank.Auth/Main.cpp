#include <iostream>
#include <windows.h>
#include <psapi.h>
#include <Logger.hpp>
#include <Database/Database.hpp>
#include <Utilities/Utils.hpp>
#include <Data/Configs/AuthConfig.hpp>
#include <Data/Managers/AccountManager.hpp>
#include <Data/ServersInfo.hpp>
#include <Data/ChannelsInfo.hpp>
#include <Data/RanksInfo.hpp>
#include <Data/MissionsInfo.hpp>
#include <AuthManager.hpp>

void UpdateConsoleTitle() {
    while (true) {
        PROCESS_MEMORY_COUNTERS_EX pmc;
        GetProcessMemoryInfo(GetCurrentProcess(), reinterpret_cast<PROCESS_MEMORY_COUNTERS*>(&pmc), sizeof(pmc));
        
        SetConsoleTitle(std::format("Point Blank - Auth | [Clients: {}, Used RAM: {}KB]", GetAuthManager()->GetTotalClients(), pmc.WorkingSetSize / 1024).c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
    try {
        std::thread(&UpdateConsoleTitle).detach();
        Logger::Print("Starting Point Blank - Auth | Build Date: {} {}", __TIME__, __DATE__);

        if (!GetConfig()->Load())
            throw std::runtime_error("Failed to load configuration for authentication server.");

        if (!GetDatabase()->Connect())
            throw std::runtime_error("Failed to connect MySQL Server, please check server configuration.");
        GetAccountManager()->Setup(GetDatabase()->GetConnection());

        GetServersInfo()->Load();
        GetChannelsInfo()->Load(GetConfig()->GetServerID());
        GetRanksInfo()->Load();
        GetRanksInfo()->LoadAwards();
        GetMissionsInfo()->Load();

        if (GetAuthManager()->Start())
            Logger::Print("Server Started.");
    }
    catch (const std::runtime_error& e) {
        Logger::PrintBad(e.what());
        system("pause");
        exit(EXIT_FAILURE);
    }
    while (true) ;
}