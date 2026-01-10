#ifndef SHEARS_H
#define SHEARS_H
#include "../Tool.h"

class Shears : public Tool {
public:
    Shears() : Tool('t') {}
    ~Shears() override;

    bool use(Soil* soil) override;
    Tool* clone() const override { return new Shears(*this); }
};

#endif