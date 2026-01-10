#include "ExitCmd.h"

bool ExitCmd::execute(std::istringstream &args) {
    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not require extra arguments." << std::endl;
        return false;
    }
    getSimulator()->stop();
    return true;
}