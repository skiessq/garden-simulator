#ifndef EXECUTE_CMD_H
#define EXECUTE_CMD_H

#include "../Command.h"
#include <iostream>

class ExecuteCmd : public Command {
public:
    ExecuteCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif