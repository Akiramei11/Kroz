#pragma once
#include "Entity.h"

class Gateway : public Entity 
{
public:
	Gateway(std::ifstream& inputFile);

	void look() override;
	void unlock(Entity* key) override;


	std::string getDirection();
	std::string getDestination();
	bool is_open();

	void openGateway();
	void closeGateway();

private:
	std::string destination;
	std::string direction;
	bool open;
	bool locked;
	std::string key;
};

