#ifndef BUY_CMD_H
#define BUY_CMD_H

#include "../Command.h"
#include <iostream>

class BuyCmd : public Command {
public:
    BuyCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif