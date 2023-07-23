#pragma once
#include "Entity.h"

class Gateway : public Entity
{
public:
	Gateway(std::ifstream& inputFile);
private:
	std::string destination;
	std::string direction;
	bool open;
	bool locked;
};

