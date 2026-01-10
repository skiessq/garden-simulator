#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>
#include <vector>

#include "Garden/Garden.h"
#include "Gardener/Gardener.h"
#include "Commands/CommandFactory.h"

class Command;

struct GardenCopy {
    std::string name;
    Garden* copied_garden;
};

class Simulator {
    Garden* current_garden;
    Gardener* gardener;
    bool running;

    std::vector<GardenCopy> saved_copies;

    int findCopyByName(const std::string& name) const;

public:
    Simulator();
    ~Simulator();

    void handleCommand(const std::string &command_line);

    void start();

    Garden* getGarden() const { return current_garden; }
    Gardener* getGardener() const { return gardener; }

    void stop() { running = false; }
    void setGarden(Garden* new_garden);
    void processFile(const std::string& filename);

    void saveCopy(const std::string& name);
    void loadCopy(const std::string& name);
    void deleteCopy(const std::string& name);
};

#endif