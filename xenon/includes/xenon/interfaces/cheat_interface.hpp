#pragma once

class ICheat {
public:
	virtual void Run() = 0;

	virtual ~ICheat() = default;
};