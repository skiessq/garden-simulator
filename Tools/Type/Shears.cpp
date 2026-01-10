#include "Shears.h"
#include "../../Garden/Soil.h"
#include "../../Plants/Plant.h"
#include <iostream>

Shears::~Shears() {}

bool Shears::use(Soil* soil) {
    if (soil == nullptr) return true;

    if (soil->hasPlant()) {
        Plant* p = soil->getPlant();
        if (p->getBeauty() == "ugly") {

            Plant* removedPlant = soil->removePlant();

            delete removedPlant;

            std::cout << "The Shears cut an ugly plant at this position!\n";
        }
    }
    return true;
}