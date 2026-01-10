#include "Garden.h"
#include <iostream>

#include "../Tools/Type/Fertilizer.h"
#include "../Tools/Type/ToolZ.h"
#include "../Tools/Type/WateringCan.h"
#include "../Tools/Type/Shears.h"
#include "../Settings/Random.h"

Garden::Garden(int r, int c) : rows(r), cols(c), gardener(nullptr) {
    grid = new Soil*[rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new Soil[cols];
    }

    for(int i = 0; i < 3; i++) {
        placeRandomTool();
    }
}

Garden::~Garden() {
    for (int i = 0; i < rows; i++) {
        delete[] grid[i];
    }

    delete[] grid;
}

void Garden::placeRandomTool() {
    bool placed = false;

    while (!placed) {
        int r = Random::getRandom(0, rows - 1);
        int c = Random::getRandom(0, cols - 1);

        if (!grid[r][c].hasTool()) {
            Tool* newTool;
            int type = Random::getRandom(0, 3);

            switch (type) {
                case 0: newTool = new Fertilizer(); break;
                case 1: newTool = new ToolZ(); break;
                case 2: newTool = new Shears(); break;
                case 3: default: newTool = new WateringCan(); break;
            }

            grid[r][c].setTool(newTool);
            placed = true;
        }
    }
}

Soil* Garden::getSoil(int r, int c) const {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        return &grid[r][c];
    }
    return nullptr;
}

void Garden::show() const {
    std::cout << "Garden " << rows << "x" << cols << "\n";
    std::cout << "Time: " << current_time << "" << std::endl;
    std::cout << "  ";
    for (int c = 0; c < cols; c++) {
        std::cout << char('A' + c) << " ";
    }
    std::cout << "\n";

    for (int r = 0; r < rows; r++) {
        std::cout << char('A' + r) << " ";
        for (int c = 0; c < cols; c++) {
            std::cout << grid[r][c].getVisualRepresentation() << " ";
        }
        std::cout << "\n";
    }
}

bool Garden::plant(const std::string& pos,  char type) {
    char row = pos[0] - 'a';
    char col = pos[1] - 'a';

    if (plants_planted_this_turn == max_plantings) {
        show();
        std::cout << "You have already planted 2 plants this instant, advance to plant more (advance [n])\n";
        return false;
    }

    if (row < rows && col < cols) {
        if (!grid[row][col].hasPlant()) {
            Plant* newPlant = Plant::create(type);
            grid[row][col].setPlant(newPlant);
            std::cout << "Plant " << type << " placed at " << pos[0] <<  pos[1] << " successfully.\n";
            show();
            plants_planted_this_turn++;
            return true;
        }
        show();
        std::cout << "There is already a plant at that position.\n";
        return false;
    }
    show();
    std::cout << "Command invalid because positions are out of garden bounds." << std::endl;
    return false;
}

void Garden::listArea() {
    bool foundSomething = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::string pos = {char('a' + i), char ('a' + j)};
            if (grid[i][j].hasPlant()) {
                foundSomething = true;
                std::cout << "Plant at position " << char('a' + i) <<  char('a' + j) << ":\n"
                << "- Plant Type: " << grid[i][j].getPlant()->getSymbol() << ",\n"
                << "- Plant Water: " << grid[i][j].getPlant()->getWater() << ",\n"
                << "- Soil Water: " << grid[i][j].getWater() << ",\n"
                << "- Plant Nutrients: " << grid[i][j].getPlant()->getNutrients() << ",\n"
                << "- Soil Nutrients: " << grid[i][j].getNutrients() << ",\n"
                << "- Plant Beauty: " << grid[i][j].getPlant()->getBeauty() << ".\n";
            } else if (grid[i][j].hasTool()) {
                foundSomething = true;
                std::cout << "Tool at position " << char('a' + i) << char('a' + j) << ":\n"
                << "- Type: " << grid[i][j].getTool()->getSymbol() << ",\n";
            }
        }
    }
    if (gardener != nullptr && gardener->isInGarden()) {
        foundSomething = true;
        std::cout << "Gardener at position " << char(gardener->getRow()) << char(gardener->getCol()) << "\n";
    }

    if (!foundSomething) {
        std::cout << "The garden is empty.\n";
    }
}

void Garden::listPlants() {
    bool found_plants = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].hasPlant()) {
                found_plants = true;
                std::cout << "Plant at position " << char('a' + i) <<  char('a' + j) << ":\n"
                << "- Plant Type: " << grid[i][j].getPlant()->getSymbol() << ",\n"
                << "- Plant Water: " << grid[i][j].getPlant()->getWater() << ",\n"
                << "- Soil Water: " << grid[i][j].getWater() << ",\n"
                << "- Plant Nutrients: " << grid[i][j].getPlant()->getNutrients() << ",\n"
                << "- Soil Nutrients: " << grid[i][j].getNutrients() << ",\n"
                << "- Plant Beauty: " << grid[i][j].getPlant()->getBeauty() << ".\n";
            }
        }
    }

    if (!found_plants) {
        std::cout << "No plants planted in the garden.\n";
    }
}

bool Garden::listPlant(const std::string& pos) {
    char row = pos[0] - 'a';
    char col = pos[1] - 'a';

    if (row < rows && col < cols) {
        if (grid[row][col].hasPlant()) {
            std::cout << "Plant at position " << pos[0] << pos[1] << ":\n"
            << "- Type: " << grid[row][col].getPlant()->getSymbol() << ",\n"
            << "- Water: " << grid[row][col].getPlant()->getWater() << ",\n"
            << "- Nutrients: " << grid[row][col].getPlant()->getNutrients() << ",\n"
            << "- Beauty: " << grid[row][col].getPlant()->getBeauty() << ",\n";
            return true;
        }
        std::cout << "No plant exists at this position" << std::endl;
        return false;
    }
    std::cout << "Command invalid because positions are out of garden bounds." << std::endl;
    return false;
}

bool Garden::harvest(const std::string& pos) {
    char row = pos[0] - 'a';
    char col = pos[1] - 'a';

    if (plants_harvested_this_turn == max_harvests) {
        show();
        std::cout << "You have already harvested 5 plants this instant, advance to harvest more (advance [n])\n";
        return false;
    }

    if (row < rows && col < cols) {
        if (grid[row][col].hasPlant()) {
            grid[row][col].setPlant(nullptr);
            show();
            std::cout << "Plant at " << pos[0] << pos[1] << " removed successfully.\n";
            plants_harvested_this_turn++;
            return true;
        }
        show();
        std::cout << "No plant to remove at this position" << std::endl;
        return false;
    }
    show();
    std::cout << "Command invalid because positions are out of garden bounds." << std::endl;
    return false;
}

void Garden::listSoil(const std::string& pos, int radius) {
    char row = pos[0] - 'a';
    char col = pos[1] - 'a';

    int row_min = std::max(0, row - radius);
    int row_max = std::min(rows - 1, row + radius);
    int col_min   = std::max(0, col - radius);
    int col_max   = std::min(cols - 1, col + radius);
    bool foundSomething = false;
    for (int i = row_min; i <= row_max; i++) {
        for (int j = col_min; j <= col_max; j++) {
            std::string currentPos = {char('a' + i), char('a' + j)};
            if (grid[i][j].hasPlant()) {
                foundSomething = true;
                std::cout << "Plant at position " << currentPos << ":\n"
                << "- Plant Type: " << grid[i][j].getPlant()->getSymbol() << ",\n"
                << "- Plant Water: " << grid[i][j].getPlant()->getWater() << ",\n"
                << "- Soil Water: " << grid[i][j].getWater() << ",\n"
                << "- Plant Nutrients: " << grid[i][j].getPlant()->getNutrients() << ",\n"
                << "- Soil Nutrients: " << grid[i][j].getNutrients() << ",\n"
                << "- Plant Beauty: " << grid[i][j].getPlant()->getBeauty() << ".\n";
            } else if (grid[i][j].hasTool()) {
                foundSomething = true;
                std::cout << "Tool at position " << currentPos << ":\n"
                << "- Type: " << grid[i][j].getTool()->getSymbol() << ",\n";
            } else if (gardener != nullptr && gardener->isInGarden() && gardener->getRow() == 'a' + i && gardener->getCol() == 'a' + j) {
                foundSomething = true;
                std::cout << "Gardener at position " << currentPos << "\n";
            }
        }
    }
    if (!foundSomething) {
        std::cout << "Nothing found in this radius centered at position " << pos << ".\n";
    }
}

void Garden::processMultiplication() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            Soil* currentSoil = &grid[i][j];

            if (currentSoil->hasPlant() && currentSoil->getPlant()->wantsToMultiply()) {

                Plant* motherPlant = currentSoil->getPlant();
                bool multiplied = false;

                for (int dx = -1; dx <= 1 && !multiplied; dx++) {
                    for (int dy = -1; dy <= 1 && !multiplied; dy++) {

                        if (dx == 0 && dy == 0) continue;

                        int neighborRow = i + dx;
                        int neighborCol = j + dy;

                        if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
                            Soil* neighborSoil = &grid[neighborRow][neighborCol];

                            bool neighborEmpty = !neighborSoil->hasPlant();
                            bool weedInvading = (motherPlant->isInvasive() &&
                                                  neighborEmpty == false &&
                                                  !neighborSoil->getPlant()->isInvasive());

                            if (neighborEmpty || weedInvading) {
                                if (weedInvading) {
                                    Plant* dead = neighborSoil->removePlant();
                                    delete dead;
                                }

                                Plant* newPlant = motherPlant->duplicate();
                                neighborSoil->setPlant(newPlant);
                                multiplied = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Garden::advance(int n_instants) {
    for (int k = 0; k < n_instants; k++) {

        if (gardener != nullptr && gardener->isInGarden()) {
            gardener->useTool(this);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Soil* soil = &grid[i][j];

                if (soil->hasPlant()) {
                    Plant* p = soil->getPlant();

                    p->process(soil);

                    if (p->isDead()) {
                        Plant* dead = soil->removePlant();
                        delete dead;
                    }
                }
            }
        }
        processMultiplication();
        current_time++;
    }
}

Garden::Garden(const Garden& other)
    : rows(other.rows), cols(other.cols), current_time(other.current_time),
      gardener(other.gardener)
{
    grid = new Soil*[rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new Soil[cols];
        for (int j = 0; j < cols; j++) {
            grid[i][j].clone(other.grid[i][j]);
        }
    }
    this->plants_planted_this_turn = other.plants_planted_this_turn;
    this->max_harvests = other.max_harvests;
    this->max_plantings = other.max_plantings;
    this->plants_harvested_this_turn = other.plants_harvested_this_turn;
    this->current_time = other.current_time;
}
