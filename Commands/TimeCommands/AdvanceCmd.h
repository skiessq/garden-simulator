#ifndef ADVANCE_CMD_H
#define ADVANCE_CMD_H

#include "../Command.h"
#include <iostream>

class AdvanceCmd : public Command {
public:
    AdvanceCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif