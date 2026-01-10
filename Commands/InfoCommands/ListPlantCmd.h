#ifndef LIST_PLANT_CMD_H
#define LIST_PLANT_CMD_H

#include "../Command.h"
#include <iostream>

class ListPlantCmd : public Command {
public:
    ListPlantCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif