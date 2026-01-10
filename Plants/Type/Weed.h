#ifndef WEED_H
#define WEED_H

#include "../Plant.h"
#include "../../Settings/Settings.h"

class Weed : public Plant {
    int initial_water = Settings::Weed::initial_water;
    int initial_nutrients = Settings::Weed::initial_nutrients;
    int water_absorption = Settings::Weed::water_absorption;
    int nutrient_absorption = Settings::Weed::nutrient_absorption;
    int dies_instants = Settings::Weed::dies_instants;
    int multiply_nutrient_greater = Settings::Weed::multiply_nutrient_greater;
    int multiply_instants = Settings::Weed::multiply_instants;
    int new_nutrients = Settings::Weed::new_nutrients;
    int original_nutrients = Settings::Weed::original_nutrients;

    int age = 0;
    int multiply_counter = 0;
public:
    Weed():Plant('e',Settings::Weed::initial_water,Settings::Weed::initial_nutrients, "ugly") {}

    void process(Soil* soil) override;
    void waterPlant(double amount) override;
    void fertilize(int amount) override;
    bool wantsToMultiply() const override;
    bool isInvasive() const override { return true; }

    Plant* clone() const override { return new Weed(*this); }
    Plant* duplicate() override;
};

#endif