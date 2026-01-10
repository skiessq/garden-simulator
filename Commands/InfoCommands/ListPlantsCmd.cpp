#include "ListPlantsCmd.h"

bool ListPlantsCmd::execute(std::istringstream &args) {
    std::string extra_args;

    if (args >> extra_args) {
        std::cout << "Error. The command does not accept arguments." << std::endl;
        return false;
    }

    Garden* garden = getSimulator()->getGarden();
    garden->listPlants();
    return true;
}
