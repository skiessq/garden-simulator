#include "Fertilizer.h"
#include "../../Garden/Soil.h"
#include <iostream>

Fertilizer::~Fertilizer() {}

bool Fertilizer::use(Soil* soil) {
    if (quantity <= 0) return false;

    if (soil != nullptr) {
        soil->addNutrients(dose);
        quantity -= dose;

        std::cout << "You applied fertilizer! The soil gained " << dose
                  << " nutrients. (Remaining: " << quantity << ")\n";
    }

    if (quantity <= 0) {
        std::cout << "The fertilizer packet is empty and the wind blew it to the neighbor's yard.\n";
        return false;
    }

    return true;
}