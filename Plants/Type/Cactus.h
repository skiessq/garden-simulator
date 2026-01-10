#ifndef CACTUS_H
#define CACTUS_H

#include "../Plant.h"
#include "../../Settings/Settings.h"

class Cactus : public Plant {
    int water_absorption_percentage = Settings::Cactus::water_absorption_percentage;
    int nutrient_absorption = Settings::Cactus::nutrient_absorption;
    int dies_water_soil_greater = Settings::Cactus::dies_water_soil_greater;
    int dies_water_soil_instants = Settings::Cactus::dies_water_soil_instants;
    int dies_nutrient_soil_less = Settings::Cactus::dies_nutrient_soil_less;
    int dies_nutrient_soil_instants = Settings::Cactus::dies_nutrient_soil_instants;
    int multiply_nutrient_greater = Settings::Cactus::multiply_nutrient_greater;
    int multiply_water_greater = Settings::Cactus::multiply_water_greater;
    int excessive_water_days_counter = 0;
    int no_nutrients_days_counter = 0;
public:
    Cactus() : Plant('c', 0, 0, "neutral") {}

    void process(Soil* soil) override;
    void waterPlant(double amount) override;
    void fertilize(int amount) override;
    bool wantsToMultiply() const override;

    Plant* clone() const override { return new Cactus(*this); }
    Plant* duplicate() override;
};

#endif
