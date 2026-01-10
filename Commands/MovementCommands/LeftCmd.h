#ifndef LEFT_CMD_H
#define LEFT_CMD_H

#include "../Command.h"
#include <iostream>

class LeftCmd : public Command {
public:
    LeftCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif