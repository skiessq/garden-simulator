#ifndef LIST_PLANTS_CMD_H
#define LIST_PLANTS_CMD_H

#include "../Command.h"
#include <iostream>

class ListPlantsCmd : public Command {
public:
    ListPlantsCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif