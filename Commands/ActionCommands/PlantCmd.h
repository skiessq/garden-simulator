#ifndef PLANT_CMD_H
#define PLANT_CMD_H

#include "../Command.h"
#include <iostream>

class PlantCmd : public Command {
public:
    PlantCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif