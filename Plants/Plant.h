#ifndef PLANT_H
#define PLANT_H

#include <string>
class Soil;

class Plant {
    double water;
    int nutrients;
    char symbol;
    std::string beauty;

    bool is_dead = false;
public:
    Plant(char s, int w, int n, std::string b);
    virtual ~Plant() {}

    char getSymbol() const { return symbol; }
    double getWater() const { return water; }
    int getNutrients() const { return nutrients; }
    std::string getBeauty() const { return beauty; }
    bool isDead() const { return is_dead; }
    void setIsDead(bool status) { is_dead = status; }

    void setWater(double w) { water = w; }
    void setNutrients(int n) { nutrients = n; }
    virtual void process(Soil* soil) = 0;

    virtual void waterPlant(double amount) { water += amount; }
    virtual void fertilize(int amount) { nutrients += amount; }
    virtual bool wantsToMultiply() const { return false; }
    virtual bool isInvasive() const { return false; }
    static Plant* create(char symbol);
    virtual Plant* duplicate() { return nullptr; }
    virtual Plant* clone() const = 0;
};

#endif