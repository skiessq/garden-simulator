#ifndef TOOLZ_H
#define TOOLZ_H
#include "../Tool.h"

class ToolZ : public Tool {
public:
    ToolZ() : Tool('z') {}
    ~ToolZ() override;

    bool use(Soil* soil) override;

    Tool* clone() const override { return new ToolZ(*this); }
};

#endif