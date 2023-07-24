#include "NPC.h"
#include "Item.h"

NPC::NPC(std::ifstream& inputFile) {
    std::string line;

    while (std::getline(inputFile, line)) {
        size_t pos = line.find_first_not_of(" \t");
        if (pos != std::string::npos) {
            line.erase(0, pos);
        }
        if (line.compare(0, std::string("name: ").length(), "name: ") == 0) {
            setName(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("description: ").length(), "description: ") == 0) {
            setDescription(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("maxHealth: ").length(), "maxHealth: ") == 0) {
            setMaxHealth(stoi(getStringAfterColon(line)));
            setHealth(stoi(getStringAfterColon(line)));
        }
        else if (line.compare(0, std::string("hostile: ").length(), "health: ") == 0) {
            hostile = stringToBool(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("Item").length(), "Item") == 0) {
            addElement(new Item(inputFile));
        }
        else if (line == "}") {
            break;
        }
    }
}