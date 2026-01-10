#include "Weed.h"
#include "../../Garden/Soil.h"

void Weed::process(Soil *soil) {
    this->age++;
    this->multiply_counter++;

    if (this->age >= dies_instants) {
        this->setIsDead(true);
        return;
    }

    if (soil != nullptr) {
        if (soil->getWater() >= water_absorption) {
            soil->addWater(-water_absorption);
            this->waterPlant(water_absorption);
        }

        if (soil->getNutrients() >= nutrient_absorption) {
            soil->addNutrients(-nutrient_absorption);
            this->fertilize(nutrient_absorption);
        }
    }
}

void Weed::waterPlant(double amount) {
    Plant::waterPlant(amount);
}

void Weed::fertilize(int amount) {
    Plant::fertilize(amount);
}

bool Weed::wantsToMultiply() const {
    return (this->getNutrients() > multiply_nutrient_greater) &&
           (this->multiply_counter >= multiply_instants);
}

Plant * Weed::duplicate() {
    this->multiply_counter = 0;
    return new Weed();
}