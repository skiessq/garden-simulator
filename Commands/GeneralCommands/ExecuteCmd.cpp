#include "ExecuteCmd.h"

bool ExecuteCmd::execute(std::istringstream &args) {
    std::string filename;
    if (!(args >> filename)) {
        std::cout << "Error. The command requires a filename to execute." << std::endl;
        return false;
    }

    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not require extra arguments." << std::endl;
        return false;
    }

    getSimulator()->processFile(filename);
    return true;
}