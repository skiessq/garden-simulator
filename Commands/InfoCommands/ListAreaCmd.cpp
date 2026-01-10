#include "ListAreaCmd.h"
#include "../../Garden/Garden.h"

bool ListAreaCmd::execute(std::istringstream &args) {
    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not accept arguments." << std::endl;
        return false;
    }

    Garden* garden = getSimulator()->getGarden();
    garden->listArea();
    return true;
}