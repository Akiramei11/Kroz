#include "Game.h"
#include <fstream>

Game::Game(const std::string& levelFile) {
    world = new Entity();
    loadLevel(levelFile);
    player = new Player();
    world->getElement("Living room")->addElement(player);

    commands["north"] = std::make_unique<NorthCommand>();
    commands["south"] = std::make_unique<SouthCommand>();
    commands["east"] = std::make_unique<EastCommand>();
    commands["west"] = std::make_unique<WestCommand>();
    commands["up"] = std::make_unique<UpCommand>();
    commands["down"] = std::make_unique<DownCommand>();
    commands["look"] = std::make_unique<LookCommand>();

    commands["take"] = std::make_unique<TakeCommand>();
    commands["drop"] = std::make_unique<DropCommand>();
    commands["put"] = std::make_unique<PutCommand>();
    commands["inventory"] = std::make_unique<InventoryCommand>();
    commands["examine"] = std::make_unique<ExamineCommand>();

    commands["open"] = std::make_unique<OpenCommand>();
    commands["close"] = std::make_unique<CloseCommand>();

    commands["attack"] = std::make_unique<AttackCommand>();
    commands["consume"] = std::make_unique<ConsumeCommand>();
    commands["status"] = std::make_unique<StatusCommand>();
}

Game::~Game() {
    delete world;
    world = nullptr;

    delete player;
    player = nullptr;
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
            world->addElement(new Room(inputFile));
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

    if (commands[command]) {
        commands[command]->execute(player, args);
        return true;
    }

    return false; // Command not found.
}

bool Game::checkPlayer() {
    if (player->getParent() == nullptr) return true;
    return false;
}