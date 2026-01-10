#include "Soil.h"
#include "../Settings/Random.h"

Soil::Soil() : plant(nullptr), tool(nullptr) {
    water = Random::getRandom(80, 100);
    nutrients = Random::getRandom(40, 50);
    occupiedByGardener = false;
}

Soil::~Soil() {
    delete plant;
    delete tool;
}

char Soil::getVisualRepresentation() const {
    if (occupiedByGardener) {
        return '*';
    }
    if (plant != nullptr) {
        return plant->getSymbol();
    }
    if (tool != nullptr) {
        return tool->getSymbol();
    }
    return ' ';
}

void Soil::setGardener(bool present) {
    occupiedByGardener = present;
}

bool Soil::hasPlant() const {
    return plant != nullptr;
}

void Soil::setPlant(Plant* p) {
    if (plant != nullptr) {
        delete plant;
    }
    plant = p;
}

Plant* Soil::getPlant() const {
    return plant;
}

Plant* Soil::removePlant() {
    Plant* p = plant;
    plant = nullptr;
    return p;
}

bool Soil::hasTool() const {
    return tool != nullptr;
}

Tool* Soil::getTool() const {
    return tool;
}

void Soil::setTool(Tool* t) {
    if (tool != nullptr) {
        delete tool;
    }
    tool = t;
}

Tool* Soil::removeTool() {
    Tool* t = tool;
    tool = nullptr;
    return t;
}

void Soil::clone(const Soil& other) {
    this->water = other.water;
    this->nutrients = other.nutrients;
    this->occupiedByGardener = false;

    if (other.plant != nullptr) {
        this->plant = other.plant->clone();
    } else {
        this->plant = nullptr;
    }

    if (other.tool != nullptr) {
        this->tool = other.tool->clone();
    } else {
        this->tool = nullptr;
    }
}
