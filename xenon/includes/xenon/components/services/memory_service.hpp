#pragma once

#include <xenon/components/component.hpp>

#include <string>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <stdexcept>

/**
 * @class MemoryService
 * @brief A service for interacting with a game's process memory.
 *
 * The MemoryService class provides methods for attaching to a game's process,
 * reading from and writing to its memory, and managing the game's process lifecycle.
 * It is essential for tasks like modifying game values, reading game state, and
 * interfacing with the game at the memory level.
 */
class MemoryService : public CComponent {
public:

    /**
     * @brief Attaches to a game process using its executable path.
     * @param path The absolute path to the game's executable.
     *
     * This method finds and attaches the current process to the game specified by
     * the given path. It allows the framework to manipulate the game's memory.
     */
    void AttachGame(std::string path);

    /**
     * @brief Retrieves the base address of a module loaded into the game's process.
     * @param moduleName The name of the module (e.g., "game.exe").
     * @return The base address of the module.
     *
     * This function retrieves the base address of a specified module loaded within
     * the game's process, which can be used to read or write memory from/to the module.
     */
    const std::uintptr_t GetModuleAddress(const std::string_view moduleName) const noexcept;

    /**
     * @brief Detaches from the game process.
     *
     * This method detaches the framework from the currently attached game process,
     * releasing any resources associated with the process.
     */
    void DeattachGame();

    /**
     * @brief Checks if the game process is currently running.
     * @return `true` if the game process is running, `false` otherwise.
     *
     * This function checks the current state of the game process to determine
     * if it is still running.
     */
    bool IsGameRunning() const noexcept;

    /**
     * @brief Reads a value from memory at the given address.
     * @param address The memory address to read from.
     * @return The value stored at the specified address.
     *
     * This function reads raw memory from the game's process at the given address
     * and returns the value stored there.
     */
    uintptr_t ReadPointer(const std::uintptr_t& address);

    /**
     * @brief Writes a value to memory at the given address.
     * @param address The memory address to write to.
     * @param value The value to write to memory.
     *
     * This function writes a value to the game's memory at the specified address.
     */
    void WritePointer(const std::uintptr_t& address, const uintptr_t& value);

    /**
     * @brief Reads a value of type `T` from memory at the given address.
     * @param address The memory address to read from.
     * @return The value of type `T` stored at the specified address.
     *
     * This function reads the memory at the given address and returns it as a
     * value of type `T`. The value is read using the `ReadProcessMemory` API.
     */
    template <typename T>
    constexpr const T Read(const std::uintptr_t& address) const noexcept
    {
        T value = { };
        ::ReadProcessMemory(m_hProcessHandle, reinterpret_cast<const void*>(address), &value, sizeof(T), NULL);
        return value;
    }

    /**
     * @brief Writes a value of type `T` to memory at the given address.
     * @param address The memory address to write to.
     * @param value The value to write to memory.
     *
     * This function writes the provided value of type `T` to the game's memory
     * at the specified address using the `WriteProcessMemory` API.
     */
    template <typename T>
    constexpr void Write(const std::uintptr_t& address, const T& value) const noexcept
    {
        ::WriteProcessMemory(m_hProcessHandle, reinterpret_cast<void*>(address), &value, sizeof(T), NULL);
    }

private:
    std::string m_strGameAbsolutePath; ///< The absolute path to the game's executable.
    std::string m_strProcessName; ///< The name of the game process.
    HANDLE m_hProcessHandle; ///< Handle to the game's process.
    int m_nPid; ///< The process ID of the game.
};
