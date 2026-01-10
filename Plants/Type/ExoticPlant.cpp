#include "ExoticPlant.h"
#include "../../Garden/Soil.h"

void ExoticPlant::process(Soil *soil) {
    this->setWater(this->getWater() - water_loss);
    this->setNutrients(this->getNutrients() - nutrient_consumption);

    if (soil != nullptr) {
        double waterToDrink = (soil->getWater() >= water_consumption) ? water_consumption : soil->getWater();
        soil->addWater(-waterToDrink);
        this->waterPlant(waterToDrink);

        int nutriToEat = (soil->getNutrients() >= nutrient_consumption) ? nutrient_consumption : soil->getNutrients();
        soil->addNutrients(-nutriToEat);
        this->fertilize(nutriToEat);
    }

    if (this->getWater() <= death_water_min || this->getNutrients() <= death_nutrients_min) {
        this->setIsDead(true);

        if (soil != nullptr) {
            soil->addWater(this->getWater() + 5);
            soil->addNutrients(this->getNutrients() + 10);
        }
    }
}

void ExoticPlant::waterPlant(double amount) {
    Plant::waterPlant(amount);
}

void ExoticPlant::fertilize(int amount) {
    Plant::fertilize(amount);
}

bool ExoticPlant::wantsToMultiply() const {
    return this->getNutrients() >= multiplication_cost;
}

Plant * ExoticPlant::duplicate() {
    ExoticPlant* newPlant = new ExoticPlant();

    int halfWater = this->getWater() / 2;
    int halfNutri = this->getNutrients() / 2;

    newPlant->setWater(halfWater);
    newPlant->setNutrients(halfNutri);

    this->setWater(this->getWater() - halfWater);
    this->setNutrients(this->getNutrients() - halfNutri);

    return newPlant;
}