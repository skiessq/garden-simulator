#include "EnterCmd.h"
#include "../../Garden/Garden.h"

bool EnterCmd::execute(std::istringstream &args) {
    std::string position;

    if (!(args >> position)) {
        std::cout << "Error. The command requires the position where the gardener will enter." << std::endl;
        return false;
    }

    if (position.size() != 2) {
        std::cout << "Error. The position must have exactly two letters." << std::endl;
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
        std::cout << "Error. The command accepts only one argument." << std::endl;
        return false;
    }

    Gardener* gardener = getSimulator()->getGardener();
    Garden* garden = getSimulator()->getGarden();
    gardener->enter(position, garden);
    garden->show();
    return true;
}