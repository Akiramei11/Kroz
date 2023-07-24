#include "Item.h"
#include "Gateway.h"
#include "NPC.h"

Item::Item(std::ifstream& inputFile) {
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
        else if (line.compare(0, std::string("pickable: ").length(), "pickable: ") == 0) {
            pickable = stringToBool(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("type: ").length(), "type: ") == 0) {
            int itemType = std::stoi(getStringAfterColon(line));
            switch (itemType)
            {
            case 0:
                type = ITEM;
            case 1:
                type = WEAPON;
            case 2:
                type = TOOL;
            case 3:
                type = FOOD;
            case 4:
                type = DRINK;
            case 5:
                type = DOCUMENT;
            case 6:
                type = CONTAINER;
            default:
                type = ITEM;
            }
        }
        else if (line.compare(0, std::string("open: ").length(), "open: ") == 0) {
            open = stringToBool(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("locked: ").length(), "locked: ") == 0) {
            locked = stringToBool(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("dmg: ").length(), "dmg: ") == 0) {
            dmg = std::stoi(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("Gateway").length(), "Gateway") == 0) {
            addElement(new Gateway(inputFile));
        }
        else if (line.compare(0, std::string("Item").length(), "Item") == 0) {
            addElement(new Item(inputFile));
        }
        else if (line.compare(0, std::string("Creature").length(), "Creature") == 0) {
            addElement(new NPC(inputFile));
        }
        else if (line == "}") {
            break;
        }
    }
}

void Item::look() {
    std::cout << name << ": " << description << std::endl;

    if (open) {
        for (auto ents : elements) {
            std::cout << "\t";
            ents.second->look();
        }
    }
}