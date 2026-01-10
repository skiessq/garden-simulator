#include "LeftCmd.h"
#include "../../Garden/Garden.h"

bool LeftCmd::execute(std::istringstream &args) {
    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not accept arguments." << std::endl;
        return false;
    }

    Gardener* gardener = getSimulator()->getGardener();
    Garden* garden = getSimulator()->getGarden();
    gardener->moveLeft(garden);
    garden->show();
    return true;
}