#include "OHDDump/SDK.hpp"

namespace UE {

    // default vars
    static SDK::UEngine* m_pEngine;
    static SDK::UWorld* m_pWorld;
    static SDK::APlayerController* m_pMyController;
    static SDK::APawn* m_pMyPawn;
    static SDK::ACharacter* m_pMyCharacter;

    // default fetch sdk
    static bool FetchSDK() {
        m_pEngine = SDK::UEngine::GetEngine();
        m_pWorld = SDK::UWorld::GetWorld();

        if (!m_pEngine || m_pEngine == nullptr || !m_pWorld || m_pWorld == nullptr) {
            //spdlog::error("Failed to get engine or world");
            return false;
        }

        if (!m_pWorld->OwningGameInstance) {
            //spdlog::error("Failed to get game instance");
            return false;
        }

        if (!m_pWorld->OwningGameInstance->LocalPlayers.Num()) {
            //spdlog::error("Failed to get local players");
            return false;
        }

        m_pMyController = m_pWorld->OwningGameInstance->LocalPlayers[0]->PlayerController;
        if (!m_pMyController || m_pMyController == nullptr) {
            //spdlog::error("Failed to get controller");
            return false;
        }

        m_pMyPawn = m_pMyController->AcknowledgedPawn;
        if (!m_pMyPawn || m_pMyPawn == nullptr) {
            //spdlog::error("Failed to get pawn");
            return false;
        }

        m_pMyCharacter = m_pMyController->Character;
        if (!m_pMyCharacter || m_pMyCharacter == nullptr) {
            //spdlog::error("Failed to get character");
            return false;
        }

        return true;

    }

}