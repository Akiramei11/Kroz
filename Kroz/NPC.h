#pragma once
#include "Creature.h"

class NPC : public Creature
{
public:
	NPC(std::ifstream& inputFile);
private:
	bool hostile;
};

