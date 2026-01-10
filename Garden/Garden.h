#ifndef GARDEN_H
#define GARDEN_H
#include "Soil.h"
#include "../Gardener/Gardener.h"

class Garden {
    int rows, cols;
    Soil** grid;
    Gardener* gardener;
    int current_time = 0;

    int plants_harvested_this_turn = 0;
    int plants_planted_this_turn = 0;
    int max_harvests = Settings::Gardener::max_harvests;
    int max_plantings = Settings::Gardener::max_plantings;
public:
    Garden(int r, int c);
    ~Garden();

    void setGardener(Gardener* g) { gardener = g; }

    void placeRandomTool();

    void setTime(int advance) { current_time += advance; }
    int getTime() const { return current_time; }
    void advanceTime(int n = 1) { current_time += n; }

    void resetTurn() {plants_harvested_this_turn = 0; plants_planted_this_turn = 0;}

    bool plant(const std::string& pos, char type);
    void listSoil(const std::string& pos, int radius = 1);

    void processMultiplication();

    void advance(int n_instants);

    Garden(const Garden &other);

    bool listPlant(const std::string &pos);
    void listArea();
    void listPlants();
    bool harvest(const std::string& pos);
    void show() const;

    int getRows() const {return rows;}
    int getCols() const {return cols;}

    Soil* getSoil(int r, int c) const;
};

#endif