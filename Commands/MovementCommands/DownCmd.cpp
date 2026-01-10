#include "DownCmd.h"
#include "../../Garden/Garden.h"

bool DownCmd::execute(std::istringstream &args) {
    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not accept arguments." << std::endl;
        return false;
    }
    Gardener* gardener = getSimulator()->getGardener();
    Garden* garden = getSimulator()->getGarden();
    gardener->moveDown(garden);
    garden->show();
    return true;
}