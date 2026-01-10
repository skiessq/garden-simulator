#ifndef HELP_CMD_H
#define HELP_CMD_H

#include "../Command.h"
#include <iostream>

class HelpCmd : public Command {
public:
    HelpCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif