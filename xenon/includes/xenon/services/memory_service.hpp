#include <string>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <stdexcept>

class MemoryService {
public:

    void AttachGame(std::string path);

	const std::uintptr_t GetModuleAddress(const std::string_view moduleName) const noexcept;

	void DeattachGame();

	uintptr_t ReadPointer(const std::uintptr_t& address);
	void WritePointer(const std::uintptr_t& address, const uintptr_t& value);

    template <typename T>
    constexpr const T Read(const std::uintptr_t& address) const noexcept
    {
        T value = { };
        ::ReadProcessMemory(m_hProcessHandle, reinterpret_cast<const void*>(address), &value, sizeof(T), NULL);
        return value;
    }

    template <typename T>
    constexpr void Write(const std::uintptr_t& address, const T& value) const noexcept
    {
        ::WriteProcessMemory(m_hProcessHandle, reinterpret_cast<void*>(address), &value, sizeof(T), NULL);
    }

private:
    std::string m_strGameAbsolutePath;
    std::string m_strProcessName;
    HANDLE m_hProcessHandle;
    int m_nPid;
};