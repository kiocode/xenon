#include <xenon/utility/vec2.hpp>

struct Vec2Int {
	int x, y;
};

class Player {
public:
	int id;
	int gametick;
	bool frozen;
	Vec2 pos;
	Vec2 vel;
};