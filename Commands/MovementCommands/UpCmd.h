#ifndef UP_CMD_H
#define UP_CMD_H

#include "../Command.h"
#include <iostream>

class UpCmd : public Command {
public:
    UpCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif