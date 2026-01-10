#include "ListToolsCmd.h"

bool ListToolsCmd::execute(std::istringstream &args) {
    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not accept arguments." << std::endl;
        return false;
    }

    Gardener* gardener = getSimulator()->getGardener();
    gardener->listTools();
    return true;
}
