#include "WateringCan.h"
#include "../../Garden/Soil.h"
#include <iostream>

WateringCan::~WateringCan() {}

bool WateringCan::use(Soil* soil) {
    if (water <= 0) return false;
    if (soil != nullptr) {
        soil->addWater(dose);
        this->water -= dose;

        std::cout << "The Watering Can watered the soil with " << dose << " units of water. (Remaining: " << water << ")\n";
    }

    if (water <= 0) {
        std::cout << "The Watering Can is empty! The gardener threw it far away.\n";
        return false;
    }

    return true;
}
