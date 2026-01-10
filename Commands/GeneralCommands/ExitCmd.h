#ifndef EXIT_CMD_H
#define EXIT_CMD_H

#include "../Command.h"
#include <iostream>

class ExitCmd : public Command {
public:
    ExitCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif