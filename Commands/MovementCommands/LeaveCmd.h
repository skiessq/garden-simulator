#ifndef LEAVE_CMD_H
#define LEAVE_CMD_H

#include "../Command.h"
#include <iostream>

class LeaveCmd : public Command {
public:
    LeaveCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif