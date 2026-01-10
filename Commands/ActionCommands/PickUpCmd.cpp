#include "PickUpCmd.h"

bool PickUpCmd::execute(std::istringstream &args) {
    int tool_id;

    if (!(args >> tool_id)) {
        std::cout << "Error. The command requires arguments and valid argument (e.g. pickup 1)." << std::endl;
        return false;
    }

    if (tool_id <= 0) {
        std::cout << "Error. The tool ID must be a positive integer." << std::endl;
        return false;
    }

    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command only requires the tool ID to pick up (e.g. pickup 1)." << std::endl;
        return false;
    }

    Gardener* gardener = getSimulator()->getGardener();
    gardener->pickUp(tool_id);
    return true;
}