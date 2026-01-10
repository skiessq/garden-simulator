#ifndef ROSE_H
#define ROSE_H

#include "../Plant.h"
#include "../../Settings/Settings.h"

class Rose : public Plant {
    int initial_water = Settings::Rose::initial_water;
    int initial_nutrients = Settings::Rose::initial_nutrients;
    int water_loss = Settings::Rose::water_loss;
    int nutrient_loss = Settings::Rose::nutrient_loss;
    int water_absorption = Settings::Rose::water_absorption;
    int nutrient_absorption = Settings::Rose::nutrient_absorption;
    int dies_water_less = Settings::Rose::dies_water_less;
    int dies_nutrient_less = Settings::Rose::dies_nutrient_less;
    int dies_nutrient_greater = Settings::Rose::dies_nutrient_greater;
    int multiply_nutrient_greater = Settings::Rose::multiply_nutrient_greater;
    int new_nutrients = Settings::Rose::new_nutrients;
    int new_water_percentage = Settings::Rose::new_water_percentage;
    int original_nutrients = Settings::Rose::original_nutrients;
    int original_water_percentage = Settings::Rose::original_water_percentage;

public:
    Rose() : Plant('r',Settings::Rose::initial_water,Settings::Rose::initial_nutrients, "beautiful") {}

    void process(Soil* soil) override;
    void waterPlant(double amount) override;
    void fertilize(int amount) override;
    bool wantsToMultiply() const override;

    Plant* clone() const override { return new Rose(*this); }
    Plant* duplicate() override;
};

#endif
