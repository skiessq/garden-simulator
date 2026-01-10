#ifndef HARVEST_CMD_H
#define HARVEST_CMD_H

#include "../Command.h"
#include <iostream>

class HarvestCmd : public Command {
public:
    HarvestCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif