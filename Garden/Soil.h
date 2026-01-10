#ifndef SOIL_H
#define SOIL_H
#include "../Tools/Tool.h"
#include "../Plants/Plant.h"

class Soil {
    double water;
    int nutrients;
    Plant* plant;
    Tool* tool;
    bool occupiedByGardener = false;
public:
    Soil();
    ~Soil();

    char getVisualRepresentation() const;
    void setGardener(bool present);
    double getWater() const {return water;}
    int getNutrients() const {return nutrients;}

    void addWater(double value) {water += value;}
    void addNutrients(int value) {nutrients += value;}

    bool hasPlant() const;
    void setPlant(Plant* p);
    Plant* getPlant() const;
    Plant* removePlant();

    bool hasTool() const;
    void setTool(Tool* t);
    Tool* getTool() const;
    Tool* removeTool();

    void clone(const Soil &other);
};

#endif