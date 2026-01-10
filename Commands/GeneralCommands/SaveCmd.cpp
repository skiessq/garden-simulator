#include "SaveCmd.h"

bool SaveCmd::execute(std::istringstream &args) {
    std::string save;
    if (!(args >> save)) {
        std::cout << "Error. The command requires a name to save a copy." << std::endl;
        return false;
    }

    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not require extra arguments." << std::endl;
        return false;
    }

    getSimulator()->saveCopy(save);
    Garden* garden = getSimulator()->getGarden();
    if (garden) garden->show();
    return true;
}