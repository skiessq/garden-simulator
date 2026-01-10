#include "DropCmd.h"

bool DropCmd::execute(std::istringstream &args) {
    std::string extra_args;

    if (args >> extra_args) {
        std::cout << "Error. The command should not have arguments" << std::endl;
        return false;
    }

    Gardener* gardener = getSimulator()->getGardener();
    gardener->drop();
    return true;
}