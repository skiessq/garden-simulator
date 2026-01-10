#include "ListSoilCmd.h"

bool ListSoilCmd::execute(std::istringstream &args) {
    std::string position;
    int radius = 0;

    if (!(args >> position)) {
        std::cout << "Error. The command requires arguments." << std::endl;
        return false;
    }

    if (position.size() != 2) {
        std::cout << "Error. The command requires a position (e.g., df)." << std::endl;
        return false;
    }

    for (char letter : position) {
        if (letter < 'a' || letter > 'z') {
            std::cout << "Error. The position must contain only lowercase letters." << std::endl;
            return false;
        }
    }

    if (args >> radius) {
        if (radius <= 0) {
            std::cout << "Error. The radius must be a positive value." << std::endl;
            return false;
        }
    } else {
        std::cout << "Radius not entered, radius = 1." << std::endl;
        radius = 1;
    }

    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. Only two arguments are allowed (e.g., listsoil df 2)." << std::endl;
        return false;
    }

    Garden* garden = getSimulator()->getGarden();
    garden->listSoil(position, radius);
    return true;
}
