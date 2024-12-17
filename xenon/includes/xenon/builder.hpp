#include "di_manager.hpp"

class Builder {
public:
	DIManager Services;

    void SetDebugLogLevel();
    void SetInfoLogLevel();
    void SetErrorLogLevel();
};
