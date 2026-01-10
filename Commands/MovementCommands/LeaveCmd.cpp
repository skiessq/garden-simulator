#include "LeaveCmd.h"
#include "../../Garden/Garden.h"

bool LeaveCmd::execute(std::istringstream &args) {
    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not require arguments" << std::endl;
        return false;
    }

    Gardener* gardener = getSimulator()->getGardener();
    Garden* garden = getSimulator()->getGarden();
    gardener->leave(garden);
    garden->show();
    return true;
}