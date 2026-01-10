#ifndef DELETE_CMD_H
#define DELETE_CMD_H

#include "../Command.h"
#include <iostream>

class DeleteCmd : public Command {
public:
    DeleteCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif