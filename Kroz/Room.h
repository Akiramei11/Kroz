#pragma once
#include "Entity.h"

class Room : public Entity
{
public:
	Room();
	~Room();
	Room(std::ifstream& inputFile);
	Entity* getGateway(const std::string& dest);
	Entity* getGatewayDirection(const std::string& dest);
	Entity* deepSearch(const std::string& toSearch);

private:

};

