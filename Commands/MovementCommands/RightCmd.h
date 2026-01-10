#ifndef RIGHT_CMD_H
#define RIGHT_CMD_H

#include "../Command.h"
#include <iostream>

class RightCmd : public Command {
public:
    RightCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif