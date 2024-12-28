#include <xenon/core/cheat.hpp>
#include <kiero/kiero.h>
#include <xenon/services/gui_service.hpp>
#include <xenon/core/di_manager.hpp>

void Cheat::Run() {

    if (m_pSystem->IsInternal()) {
        spdlog::info("Internal cheat initialized");

        bool bInitialized = false;
        do
        {
            if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
            {
                m_pGame->EnableUpdate();
                bInitialized = true;
            }
        } while (!bInitialized);
    }
    else {
        spdlog::info("External cheat initialized");

        m_pGame->EnableUpdate();
    }
}

#pragma region Cheat:Private


#pragma endregion
