#include "Gateway.h"
#include <fstream>

Gateway::Gateway(std::ifstream& inputFile) {
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
        else if (line.compare(0, std::string("destination: ").length(), "destination: ") == 0) {
            destination = getStringAfterColon(line);
        }
        else if (line.compare(0, std::string("direction: ").length(), "direction: ") == 0) {
            direction = getStringAfterColon(line);
        }
        else if (line.compare(0, std::string("open: ").length(), "open: ") == 0) {
            open = stringToBool(getStringAfterColon(line));
        }
        else if (line.compare(0, std::string("locked: ").length(), "locked: ") == 0) {
            locked = stringToBool(getStringAfterColon(line));
        }
        else if (line == "}") {
            break;
        }
    }
}

void Gateway::look() {
    if (!open) {
        std::cout << name << ": " << " It is closed." << std::endl;
    }
    else std::cout << name << ": " << description << std::endl;

    for (auto ents : elements) {
        ents.second->look();
    }
}


std::string Gateway::getDirection() {
    return direction;
}

std::string Gateway::getDestination() {
    return destination;
}

bool Gateway::is_open() {
    return open;
}

void Gateway::openGateway() {
    if (locked) {
        std::cout << "It's locked" << std::endl;
    }
    else {
        open = true;
        std::cout << "It's open" << std::endl;
    }
}

void Gateway::closeGateway() {
    open = false;
    std::cout << "It's closed" << std::endl;
}