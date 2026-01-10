#ifndef COMMAND_H
#define COMMAND_H

#include <sstream>
#include "../Simulator.h"

class Command {
    Simulator* simulator;
public:
    virtual ~Command() = default;
    virtual bool execute(std::istringstream &args) = 0;

    void setSimulator(Simulator* sim) {
        simulator = sim;
    }

protected:
    Simulator* getSimulator() const {
        return simulator;
    }
};

#endif