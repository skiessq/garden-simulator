#ifndef GARDEN_CMD_H
#define GARDEN_CMD_H

#include "../Command.h"
#include <iostream>

class GardenCmd : public Command {
public:
    GardenCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif