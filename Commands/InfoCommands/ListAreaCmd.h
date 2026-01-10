#ifndef LIST_AREA_CMD_H
#define LIST_AREA_CMD_H

#include "../Command.h"
#include <iostream>

class ListAreaCmd : public Command {
public:
    ListAreaCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif