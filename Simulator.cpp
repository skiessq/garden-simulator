#include "Simulator.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Commands/CommandFactory.h"
#include "Commands/Command.h"

Simulator::Simulator()
    : current_garden(nullptr), gardener(new Gardener()), running(true) {
            saved_copies.reserve(5);
            std::cout << "Garden Simulator started - Welcome. Type 'help' for all the commands" << std::endl;
}

Simulator::~Simulator() {
    delete current_garden;
    delete gardener;

    for (auto& copy : saved_copies)
        delete copy.copied_garden;

    std::cout << "Simulator terminated - Thank you." << std::endl;
}

void Simulator::handleCommand(const std::string& command_line) {
    if (command_line.empty()) {
        return;
    }

    std::istringstream iss(command_line);
    std::string cmd_name;
    iss >> cmd_name;

    Command* cmd = createCommand(cmd_name);

    if (cmd == nullptr) {
        std::cout << "Unknown command '" << cmd_name << "'." << std::endl;
    } else {
        cmd->setSimulator(this);

        if (current_garden == nullptr && cmd_name != "garden" && cmd_name != "execute" && cmd_name != "exit" && cmd_name != "help") {
            std::cout << "Error: You must create the garden first (command 'garden <r> <c>')." << std::endl;
        }
        else if (current_garden != nullptr && cmd_name == "garden") {
            std::cout << "Error: The garden has already been created." << std::endl;
        }
        else {
            if (!cmd->execute(iss)) {}
        }
        delete cmd;
    }
}

void Simulator::start() {
    std::string command_line;

    while (running) {
        std::cout << "--> ";
        if (!std::getline(std::cin, command_line)) {
            break;
        }
        handleCommand(command_line);
    }
}

void Simulator::setGarden(Garden* new_garden) {
    if (current_garden != nullptr) {
        delete current_garden;
    }
    current_garden = new_garden;
    if (current_garden) current_garden->setGardener(this->gardener);
}

void Simulator::processFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::cout << "Executing commands from file: " << filename << "..." << std::endl;

    std::string line;
    while (std::getline(file, line) && running) {
        if (line.empty()) continue;

        std::cout << ">> " << line << std::endl;
        handleCommand(line);
    }

    file.close();
}

int Simulator::findCopyByName(const std::string& name) const {
    for (int i = 0; i < saved_copies.size(); ++i) {
        if (saved_copies[i].name == name) {
            return i;
        }
    }
    return -1;
}

void Simulator::saveCopy(const std::string& name) {
    if (!current_garden) {
        std::cout << "There is no garden to save." << std::endl;
        return;
    }

    int iCopy = findCopyByName(name);
    if (iCopy != -1) {
        std::cout << "Replacing existing copy: " << name << "..." << std::endl;
        delete saved_copies[iCopy].copied_garden;
        saved_copies[iCopy].copied_garden = new Garden(*current_garden);
        return;
    }

    GardenCopy new_copy;
    new_copy.name = name;
    new_copy.copied_garden = new Garden(*current_garden);

    saved_copies.push_back(new_copy);

    std::cout << "Garden saved with name '" << name << "'." << std::endl;
}

void Simulator::loadCopy(const std::string& name) {
    int iCopy = findCopyByName(name);
    if (iCopy == -1) {
        std::cout << "Error. Copy with name '" << name << "' not found.\n";
        return;
    }

    if (current_garden)
        delete current_garden;

    current_garden = saved_copies[iCopy].copied_garden;

    std::cout << "Garden restored from restore point (" << name << ").\n";

    saved_copies.erase(saved_copies.begin() + iCopy);
}

void Simulator::deleteCopy(const std::string& name) {
    int iCopy = findCopyByName(name);
    if (iCopy == -1) {
        std::cout << "Error. Copy with name '" << name << "' not found.\n";
        return;
    }

    delete saved_copies[iCopy].copied_garden;
    saved_copies.erase(saved_copies.begin() + iCopy);

    std::cout << "Copy '" << name << "' deleted successfully.\n";
}
