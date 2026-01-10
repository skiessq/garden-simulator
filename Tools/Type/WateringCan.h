#ifndef WATERINGCAN_H
#define WATERINGCAN_H

#include "../../Settings/Settings.h"
#include "../Tool.h"

class WateringCan : public Tool {
    int water = Settings::WateringCan::capacity;
    int dose = Settings::WateringCan::dose;
public:
    WateringCan() : Tool('g') {}
    ~WateringCan() override;

    bool isEmpty() const { return water <= 0; }
    int remainingWater() const { return water; }

    bool use(Soil* soil) override;
    Tool* clone() const override { return new WateringCan(*this); }
};

#endif