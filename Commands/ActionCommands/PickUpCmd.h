#ifndef PICKUP_CMD_H
#define PICKUP_CMD_H

#include "../Command.h"
#include <iostream>

class PickUpCmd : public Command {
public:
    PickUpCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif