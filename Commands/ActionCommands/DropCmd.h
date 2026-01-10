#ifndef DROP_CMD_H
#define DROP_CMD_H

#include "../Command.h"
#include <iostream>

class DropCmd : public Command {
public:
    DropCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif