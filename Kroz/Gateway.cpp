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
