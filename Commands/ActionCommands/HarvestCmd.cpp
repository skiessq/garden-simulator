#include "HarvestCmd.h"

bool HarvestCmd::execute(std::istringstream &args) {
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

    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command accepts only 1 argument (plant position)." << std::endl;
        return false;
    }

    Garden* garden = getSimulator()->getGarden();
    garden->harvest(position);
    return true;
}
