#ifndef LIST_SOIL_CMD_H
#define LIST_SOIL_CMD_H

#include "../Command.h"
#include <iostream>

class ListSoilCmd : public Command {
public:
    ListSoilCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif