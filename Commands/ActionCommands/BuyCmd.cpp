#include "BuyCmd.h"

bool BuyCmd::execute(std::istringstream &args) {
    char type_entered;

    if (!(args >> type_entered)) {
        std::cout << "Error. The command requires the tool type to buy <g, a, t, z> (e.g., buy g)." << std::endl;
        return false;
    }

    if (type_entered != 'a' && type_entered != 'g' && type_entered != 't' && type_entered != 'z') {
        std::cout << "Error. The tool type must be one of these: <a, g, t, z>." << std::endl;
        return false;
    }

    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not require more than one argument (e.g., buy g)." << std::endl;
        return false;
    }

    Gardener* gardener = getSimulator()->getGardener();
    gardener->buy(type_entered);
    return true;
}