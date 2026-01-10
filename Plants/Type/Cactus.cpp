#include "Cactus.h"

#include "../../Garden/Soil.h"

void Cactus::process(Soil* soil) {

    if (this->isDead()) {
        return;
    }

    double waterInSoil = soil->getWater();
    double waterToAbsorb = waterInSoil * (water_absorption_percentage / 100.0);

    soil->addWater(-waterToAbsorb);
    this->waterPlant(waterToAbsorb);

    int nutInSoil = soil->getNutrients();
    int nutToAbsorb = (nutInSoil < nutrient_absorption) ? nutInSoil : nutrient_absorption;

    soil->addNutrients(-nutToAbsorb);
    this->fertilize(nutToAbsorb);

    if (soil->getWater() > dies_water_soil_greater) {
        excessive_water_days_counter++;
    } else {
        excessive_water_days_counter = 0;
    }

    if (soil->getNutrients() <= dies_nutrient_soil_less) {
        no_nutrients_days_counter++;
    } else {
        no_nutrients_days_counter = 0;
    }

    bool diesByWater = excessive_water_days_counter >= dies_water_soil_instants;
    bool diesByNutri = no_nutrients_days_counter > dies_nutrient_soil_instants;

    if (diesByWater || diesByNutri) {
        this->setIsDead(true);

        soil->addNutrients(this->getNutrients());
        this->setNutrients(0);

    }
}

bool Cactus::wantsToMultiply() const {
    return (this->getNutrients() > multiply_nutrient_greater &&
            this->getWater() > multiply_water_greater);
}


Plant* Cactus::duplicate() {
    Cactus* newCactus = new Cactus();

    double halfWater = this->getWater() / 2.0;
    int halfNutrients = this->getNutrients() / 2;

    this->setWater(halfWater);
    this->setNutrients(halfNutrients);

    newCactus->setWater(halfWater);
    newCactus->setNutrients(halfNutrients);

    return newCactus;
}

void Cactus::waterPlant(double amount) {
    Plant::waterPlant(amount);
}

void Cactus::fertilize(int amount) {
    Plant::fertilize(amount);
}
