#ifndef DOWN_CMD_H
#define DOWN_CMD_H

#include "../Command.h"
#include <iostream>

class DownCmd : public Command {
public:
    DownCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif