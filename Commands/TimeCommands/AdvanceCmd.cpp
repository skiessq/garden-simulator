#include "AdvanceCmd.h"
#include "../../Garden/Garden.h"
#include "../../Gardener/Gardener.h"

bool AdvanceCmd::execute(std::istringstream &args) {
    int n = 1;

    if (args >> n) {
        if (n <= 0) {
            std::cout << "Error. Instants must be positive." << std::endl;
            return false;
        }
    } else {
        // Just clearing flags, not really an error if n is default
        args.clear();
    }

    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. Only one argument allowed, which must be an integer." << std::endl;
        return false;
    }

    Garden* garden = getSimulator()->getGarden();
    Gardener* gardener = getSimulator()->getGardener();
    gardener->resetTurn();
    garden->advance(n);
    garden->resetTurn();
    garden->show();
    return true;
}
