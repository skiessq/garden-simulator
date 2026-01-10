#include "Rose.h"

#include "../../Garden/Soil.h"

void Rose::process(Soil *soil) {
    double currentWater = this->getWater();
    int currentNutrients = this->getNutrients();

    currentWater -= water_loss;
    currentNutrients -= nutrient_loss;

    this->setWater(currentWater);
    this->setNutrients(currentNutrients);

    if (soil != nullptr) {
        double waterInSoil = soil->getWater();
        double waterToAbsorb = (waterInSoil >= water_absorption) ? water_absorption : waterInSoil;
        soil->addWater(-waterToAbsorb);
        this->waterPlant(waterToAbsorb);

        int nutriInSoil = soil->getNutrients();
        int nutriToAbsorb = (nutriInSoil >= nutrient_absorption) ? nutrient_absorption : nutriInSoil;
        soil->addNutrients(-nutriToAbsorb);
        this->fertilize(nutriToAbsorb);
    }

    if (this->getWater() <= dies_water_less ||
        this->getNutrients() <= dies_nutrient_less ||
        this->getNutrients() >= dies_nutrient_greater) {

        this->setIsDead(true);

        if (soil != nullptr) {
            soil->addWater(this->getWater() * 0.5);
            soil->addNutrients(this->getNutrients() / 2);
        }
    }
}

void Rose::waterPlant(double amount) {
    Plant::waterPlant(amount);
}

void Rose::fertilize(int amount) {
    Plant::fertilize(amount);
}

bool Rose::wantsToMultiply() const {
    return this->getNutrients() > multiply_nutrient_greater;
}

Plant * Rose::duplicate() {
    Rose* newPlant = new Rose();

    newPlant->setNutrients(new_nutrients);
    newPlant->setWater(this->getWater() * (new_water_percentage / 100.0));

    this->setNutrients(original_nutrients);
    this->setWater(this->getWater() * (original_water_percentage / 100.0));

    return newPlant;
}