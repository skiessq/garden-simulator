#ifndef EXOTICPLANT_H
#define EXOTICPLANT_H

#include "../Plant.h"
#include "../../Settings/Settings.h"

class ExoticPlant : public Plant {
    const int water_consumption = 2;
    const int nutrient_consumption = 1;
    const int water_loss = 1;
    const int death_water_min = 0;
    const int death_nutrients_min = 0;
    const int multiplication_cost = 40;
public:
    ExoticPlant():Plant('x',50,50, "beautiful") {}

    void process(Soil* soil) override;
    void waterPlant(double amount) override;
    void fertilize(int amount) override;
    bool wantsToMultiply() const override;

    Plant* clone() const override { return new ExoticPlant(*this); }
    Plant* duplicate() override;
};

#endif