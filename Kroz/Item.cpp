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
                break;
            case 1:
                type = WEAPON;
                break;
            case 2:
                type = TOOL;
                break;
            case 3:
                type = FOOD;
                break;
            case 4:
                type = DRINK;
                break;
            case 5:
                type = DOCUMENT;
                break;
            case 6:
                type = CONTAINER;
                break;
            default:
                type = ITEM;
                break;
            }
        }
        else if (line.compare(0, std::string("open: ").length(), "open: ") == 0) {
            open = stringToBool(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("locked: ").length(), "locked: ") == 0) {
            locked = stringToBool(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("key: ").length(), "key: ") == 0) {
            key = getStringAfterColon(line);
        }
        else if (line.compare(0, std::string("dmg: ").length(), "dmg: ") == 0) {
            dmg = std::stoi(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("healing: ").length(), "healing: ") == 0) {
            healing = std::stoi(getStringAfterColon(line));
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

Entity* Item::deepSearch(const std::string& toSearch) {
    if (name == toSearch) return this;
    else if (type == CONTAINER and open){
        for (auto element : elements) {
            if (Entity* res = element.second->deepSearch(toSearch))
                return res;
        }
    }
    return nullptr;
}

void Item::setOpen(const bool& state) {
    open = state;
}



ItemType Item::getType() {
    return type;
}

bool Item::is_pickable() {
    return pickable;
}

bool Item::is_open() {
    return open;
}

int Item::getDmg() {
    return dmg;
}

int Item::getHealing() {
    return healing;
}
std::string Item::getKey() {
    return key;
}

void Item::unlock(Entity* useKey) {
    if (key == useKey->getName()) {
        locked = false;
    }
    else std::cout << "I cant use that." << std::endl;
}
