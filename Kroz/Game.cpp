#include "Game.h"
#include <fstream>

Game::Game(const std::string& levelFile) {
    world = new Entity();
    loadLevel(levelFile);
    player = new Player();
    world->getElement("Living room")->addElements(player);

    commands["north"] = std::make_unique<NorthCommand>();
    commands["south"] = std::make_unique<SouthCommand>();
    commands["east"] = std::make_unique<EastCommand>();
    commands["west"] = std::make_unique<WestCommand>();
    commands["up"] = std::make_unique<UpCommand>();
    commands["down"] = std::make_unique<DownCommand>();
    commands["look"] = std::make_unique<LookCommand>();
    commands["go"] = std::make_unique<GoCommand>();
    commands["enter"] = std::make_unique<EnterCommand>();

    commands["take"] = std::make_unique<TakeCommand>();
    commands["drop"] = std::make_unique<DropCommand>();
    commands["throw"] = std::make_unique<ThrowCommand>();
    commands["inventory"] = std::make_unique<InventoryCommand>();
    commands["examine"] = std::make_unique<ExamineCommand>();

    commands["open"] = std::make_unique<OpenCommand>();
    commands["close"] = std::make_unique<CloseCommand>();

    commands["read"] = std::make_unique<ReadCommand>();
    commands["attack"] = std::make_unique<AttackCommand>();
    commands["drink"] = std::make_unique<DrinkCommand>();
    commands["eat"] = std::make_unique<EatCommand>();
}

Game::~Game() {
    delete player;
    delete world;
}

void Game::loadLevel(const std::string& levelFile) {

    std::ifstream inputFile(levelFile);
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = line.find_first_not_of(" \t");
        if (pos != std::string::npos) {
            line.erase(0, pos);
        }
        if (line.compare(0, std::string("Room").length(), "Room") == 0) {
            world->addElements(new Room(inputFile));
        }
        else if (line == "}") {
            break;
        }
    }

    inputFile.close();
}

bool Game::ParseCommand(std::vector<std::string>& args) {

    if (args.empty()) {
        return false;
    }
    std::string command = args[0];

    auto it = commands.find(command);
    if (it != commands.end()) {
        it->second->execute(args);
        return true;
    }

    return false; // Command not found.
}