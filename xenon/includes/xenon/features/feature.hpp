#include <nlohmann/json.hpp>

#include <xenon/models/hotkey.hpp>

class Feature {
public:

	Hotkey hotkey;

	void SaveHotkeys(const std::vector<Hotkey>& hotkeys, const std::string& filename);
	std::vector<Hotkey> LoadHotkeys(const std::string& filename);

private:
	using json = nlohmann::json;

};