#include "ToolZ.h"
#include "../../Garden/Soil.h"
#include "../../Plants/Plant.h"
#include <iostream>

ToolZ::~ToolZ() {}

bool ToolZ::use(Soil* soil) {
    if (soil == nullptr) return true;

    if (soil->hasPlant()) {
        Plant* p = soil->getPlant();
        p->setWater(100);
        p->setNutrients(100);

        std::cout << "You scattered the Star Dust! The plant " << p->getSymbol()
                  << " shined and recovered all its vitality (100 Water/100 Nutrients)!\n";

        return false;
    }
    std::cout << "There is no plant here to receive the Star Dust.\n";
    return true;
}