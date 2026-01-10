#ifndef ENTER_CMD_H
#define ENTER_CMD_H

#include "../Command.h"
#include <iostream>

class EnterCmd : public Command {
public:
    EnterCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif