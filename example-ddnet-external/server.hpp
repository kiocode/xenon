#include "player.hpp"
#include <vector>

class Server {
public:
	int localPlayerConnectedToAServer;
	int localPlayerId;
	int onlinePlayers;
	std::vector<Player> players;
};