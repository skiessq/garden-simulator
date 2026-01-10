#ifndef LOAD_CMD_H
#define LOAD_CMD_H

#include "../Command.h"
#include <iostream>

class LoadCmd : public Command {
public:
    LoadCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif