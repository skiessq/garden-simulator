#ifndef LIST_TOOLS_CMD_H
#define LIST_TOOLS_CMD_H

#include "../Command.h"
#include <iostream>

class ListToolsCmd : public Command {
public:
    ListToolsCmd() = default;
    bool execute(std::istringstream &args) override;
};

#endif