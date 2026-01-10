#include "GardenCmd.h"
#include "../../Garden/Garden.h"

bool GardenCmd::execute(std::istringstream &args) {
    int rows, cols;

    if (!(args >> rows)) {
        std::cout << "Error. The command requires two arguments <rows, cols> (e.g., garden 10 12)." << std::endl;
        return false;
    }

    if (!(args >> cols)) {
        std::cout << "Error. The command requires two arguments <rows, cols> (e.g., garden 10 12)." << std::endl;
        return false;
    }

    if (rows <= 0 || rows >= 27) {
        std::cout << "Error. The number of rows must be between [1,26]." << std::endl;
        return false;
    }

    if (cols <= 0 || cols >= 27) {
        std::cout << "Error. The number of columns must be between [1,26]." << std::endl;
        return false;
    }

    if (rows * cols < 3) {
        std::cout << "Error. The garden must have at least an area of 3 cells." << std::endl;
        return false;
    }

    if (getSimulator()->getGarden() != nullptr) {
        std::cout << "Error. The garden has already been created." << std::endl;
        return false;
    }

    Garden* new_garden = new Garden(rows, cols);
    getSimulator()->setGarden(new_garden);
    getSimulator()->getGarden()->show();
    return true;
}