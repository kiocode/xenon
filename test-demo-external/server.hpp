#include "player.hpp"

class Server {
public:
	int localPlayerConnectedToAServer;
	int localPlayerId;
	int onlinePlayers;
	std::vector<Player> players;
	Player* localPlayer;
};