#ifndef FERTILIZER_H
#define FERTILIZER_H

#include "../../Settings/Settings.h"
#include "../Tool.h"

class Fertilizer : public Tool {
    int quantity = Settings::Fertilizer::capacity;
    int dose = Settings::Fertilizer::dose;
public:
    Fertilizer() : Tool('a') {}
    ~Fertilizer() override;

    bool isEmpty() const { return quantity <= 0; }
    int remainingAmount() const { return quantity; }

    bool use(Soil* soil) override;

    Tool* clone() const override { return new Fertilizer(*this); }
};

#endif