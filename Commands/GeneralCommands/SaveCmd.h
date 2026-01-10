#ifndef SAVE_CMD_H
#define SAVE_CMD_H

#include "../Command.h"
#include <iostream>

class SaveCmd : public Command {
public:
    SaveCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif