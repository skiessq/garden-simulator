#include "DeleteCmd.h"

bool DeleteCmd::execute(std::istringstream &args) {
    std::string save;
    if (!(args >> save)) {
        std::cout << "Error. The command requires a name to delete." << std::endl;
        return false;
    }

    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not require extra arguments." << std::endl;
        return false;
    }

    getSimulator()->deleteCopy(save);
    Garden* garden = getSimulator()->getGarden();
    if (garden) garden->show();
    return true;
}