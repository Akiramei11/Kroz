#pragma once
#include "Command.h"
#include "Room.h"
#include "Player.h"
#include <map>

class Game
{
public:
    Game(const std::string& level);
    ~Game();
    void loadLevel(const std::string& level);

    bool ParseCommand(std::vector<std::string>& args);
private:
    std::map<std::string, std::unique_ptr<Command>> commands;
    Entity* world;
    Player* player;
};
