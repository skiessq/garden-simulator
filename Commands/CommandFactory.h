#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include <string>
class Command;

Command* createCommand(const std::string &name);
#endif