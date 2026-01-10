#include "PlantCmd.h"

bool PlantCmd::execute(std::istringstream &args) {
    std::string position;

    if (!(args >> position)) {
        std::cout << "Error. The command requires arguments." << std::endl;
        return false;
    }

    if (position.size() != 2) {
        std::cout << "Error. The plant position must have exactly two letters." << std::endl;
        return false;
    }

    for (char letter : position) {
        if (letter < 'a' || letter > 'z') {
            std::cout << "Error. The position must contain only lowercase letters." << std::endl;
            return false;
        }
    }

    char type_entered;
    if (!(args >> type_entered)) {
        std::cout << "Error. The command requires the type of plant to plant (c, r, e, x)." << std::endl;
        return false;
    }

    if (type_entered != 'c' && type_entered != 'r' && type_entered != 'e' && type_entered != 'x') {
        std::cout << "Error. The plant type must be one of these: <c, r, e, x>." << std::endl;
        return false;
    }

    Garden* garden = getSimulator()->getGarden();
    garden->plant(position, type_entered);
    return true;
}