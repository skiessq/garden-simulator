#include "Gardener.h"

#include <iostream>

#include "../Tools/Type/Fertilizer.h"
#include "../Tools/Type/ToolZ.h"
#include "../Tools/Type/WateringCan.h"
#include "../Tools/Type/Shears.h"
#include "../Garden/Garden.h"

Gardener::~Gardener () {
    for (auto& pair : tools) {
        delete pair.second;
    }
    tools.clear();
}

void Gardener::buy(char type) {
    Tool* newTool = nullptr;

    switch (type) {
        case 'g': newTool = new WateringCan(); break;
        case 'a': newTool = new Fertilizer(); break;
        case 't': newTool = new Shears(); break;
        case 'z': newTool = new ToolZ(); break;
        default:
            std::cout << "Invalid tool type.\n";
            return;
    }

    tools[newTool->getID()] = newTool;
    toolCount++;

    std::cout << "Bought tool " << newTool->getSymbol()
              << " with id " << newTool->getID() << ".\n";
}

void Gardener::useTool(Garden* garden) {
    if (!in_garden || !has_tool_in_hand || toolInHand == nullptr) {
        return;
    }

    Soil* currentSoil = garden->getSoil(row, col);
    bool stillWorking = toolInHand->use(currentSoil);

    if (!stillWorking) {
        tools.erase(toolInHand->getID());
        delete toolInHand;

        toolInHand = nullptr;
        has_tool_in_hand = false;
    }
}

void Gardener::enter(const std::string& pos, Garden* garden) {
    int new_row = pos[0] - 'a';
    int new_col = pos[1] - 'a';

    if (new_row >= garden->getRows() || new_col >= garden->getCols()) {
        std::cout << "This position is outside the garden bounds\n";
        return;
    }

    if (entries >= max_entries_exits) {
        std::cout << "The gardener has already entered this instant.\n";
        return;
    }

    if (in_garden) {
        garden->getSoil(row, col)->setGardener(false);

        std::cout << "Gardener teleported from position "
                  << static_cast<char>('a' + row)
                  << static_cast<char>('a' + col)
                  << " to " << pos << ".\n";
    } else {
        in_garden = true;
        std::cout << "Gardener entered the garden at position " << pos << ".\n";
    }
    row = static_cast<char>(new_row);
    col = static_cast<char>(new_col);

    garden->getSoil(row, col)->setGardener(true);
    Soil* currentSoil = garden->getSoil(row, col);
    if (currentSoil->hasTool()) {
        Tool* t = currentSoil->removeTool();
        tools[t->getID()] = t;
        toolCount++;

        std::cout << "You found a tool: " << t->getSymbol()
                  << " (ID: " << t->getID() << ")!\n";

        garden->placeRandomTool();
    }
    entries++;
}

void Gardener::pickUp(int tool_id) {
    auto it = tools.find(tool_id);
    if (it != tools.end()) {
        if (!has_tool_in_hand) {
            toolInHand = it->second;
            has_tool_in_hand = true;
            std::cout << "Picked up tool with id " << tool_id << "\n";
        } else {
            std::cout << "The gardener already has a tool in hand, use <drop> to drop the current tool" << "\n";
        }
    } else {
        std::cout << "You don't have any tool with id " << tool_id << "\n";
    }
}

void Gardener::drop() {
    if (!toolInHand) {
        std::cout << "You don't have any tool in hand.\n";
        return;
    }

    std::cout << "Dropped tool " << toolInHand->getSymbol()
              << " with id " << toolInHand->getID() << ".\n";

    toolInHand = nullptr;
    has_tool_in_hand = false;
}

void Gardener::leave(Garden* garden) {
    if (!in_garden) {
        std::cout << "The gardener is already outside the garden.\n";
        return;
    }

    if (exits >= max_entries_exits) {
        std::cout << "The gardener has already left once this instant.\n";
        return;
    }

    garden->getSoil(row, col)->setGardener(false);
    in_garden = false;
    exits++;

    std::cout << "The gardener left the garden.\n";
}
void Gardener::listTools() const {
    bool foundAnyTool = false;
    for (auto& [id, t] : tools) {
        foundAnyTool = true;
        std::cout << "Tool " << id << ": " << t->getSymbol();
        if (t == toolInHand) std::cout << " (in hand)";
        std::cout << "\n";
    }

    if (!foundAnyTool)
        std::cout << "The gardener doesn't have any tools yet.\n";
}

void Gardener::moveLeft(Garden* garden) {
    if (!in_garden) {
        std::cout << "The gardener is not in the garden.\n";
        return;
    }
    if (moves_this_inst >= max_moves) {
        std::cout << "The gardener has already moved more than " <<  max_moves << " use command <advance [n]>.\n";
        return;
    }

    if (col > 0) {
        garden->getSoil(row, col)->setGardener(false);
        col--;
        garden->getSoil(row, col)->setGardener(true);
        moves_this_inst++;

        std::cout << "Moved left. Position: "
                  << static_cast<char>('a' + row)
                  << static_cast<char>('a' + col) << "\n";
        Soil* currentSoil = garden->getSoil(row, col);
        if (currentSoil->hasTool()) {
            Tool* t = currentSoil->removeTool();
            tools[t->getID()] = t;
            toolCount++;
            std::cout << "You found a tool: " << t->getSymbol() << " (ID: " << t->getID() << ")!\n";
            garden->placeRandomTool();
        }
    } else {
        std::cout << "Outside garden bounds.\n";
    }
}

void Gardener::moveRight(Garden* garden) {
    if (!in_garden) {
        std::cout << "The gardener is not in the garden.\n";
        return;
    }
    if (moves_this_inst >= max_moves) {
        std::cout << "The gardener has already moved more than " <<  max_moves << " use command <advance [n]>.\n";
        return;
    }

    if (col < garden->getCols() - 1) {
        garden->getSoil(row, col)->setGardener(false);
        col++;
        garden->getSoil(row, col)->setGardener(true);
        moves_this_inst++;

        std::cout << "Moved right. Position: "
                  << static_cast<char>('a' + row)
                  << static_cast<char>('a' + col) << "\n";
        Soil* currentSoil = garden->getSoil(row, col);
        if (currentSoil->hasTool()) {
            Tool* t = currentSoil->removeTool();
            tools[t->getID()] = t;
            toolCount++;
            std::cout << "You found a tool: " << t->getSymbol() << " (ID: " << t->getID() << ")!\n";
            garden->placeRandomTool();
        }
    } else {
        std::cout << "Outside garden bounds.\n";
    }
}

void Gardener::moveUp(Garden* garden) {
    if (!in_garden) {
        std::cout << "The gardener is not in the garden.\n";
        return;
    }
    if (moves_this_inst >= max_moves) {
        std::cout << "The gardener has already moved more than " <<  max_moves << " use command <advance [n]>.\n";
        return;
    }

    if (row > 0) {
        garden->getSoil(row, col)->setGardener(false);
        row--;
        garden->getSoil(row, col)->setGardener(true);
        moves_this_inst++;

        std::cout << "Moved up. Position: "
                  << static_cast<char>('a' + row)
                  << static_cast<char>('a' + col) << "\n";
        Soil* currentSoil = garden->getSoil(row, col);
        if (currentSoil->hasTool()) {
            Tool* t = currentSoil->removeTool();
            tools[t->getID()] = t;
            toolCount++;
            std::cout << "You found a tool: " << t->getSymbol() << " (ID: " << t->getID() << ")!\n";
            garden->placeRandomTool();
        }
    } else {
        std::cout << "Outside garden bounds.\n";
    }
}

void Gardener::moveDown(Garden* garden) {
    if (!in_garden) {
        std::cout << "The gardener is not in the garden.\n";
        return;
    }
    if (moves_this_inst >= max_moves) {
        std::cout << "The gardener has already moved more than " <<  max_moves << " use command <advance [n]>.\n";
        return;
    }

    if (row < garden->getRows() - 1) {
        garden->getSoil(row, col)->setGardener(false);
        row++;
        garden->getSoil(row, col)->setGardener(true);
        moves_this_inst++;

        std::cout << "Moved down. Position: "
                  << static_cast<char>('a' + row)
                  << static_cast<char>('a' + col) << "\n";
        Soil* currentSoil = garden->getSoil(row, col);
        if (currentSoil->hasTool()) {
            Tool* t = currentSoil->removeTool();
            tools[t->getID()] = t;
            toolCount++;
            std::cout << "You found a tool: " << t->getSymbol() << " (ID: " << t->getID() << ")!\n";
            garden->placeRandomTool();
        }
    } else {
        std::cout << "Outside garden bounds.\n";
    }
}

Gardener::Gardener(const Gardener& other) {
    this->row = other.row;
    this->col = other.col;
    this->in_garden = other.in_garden;
    this->moves_this_inst = other.moves_this_inst;
    this->entries = other.entries;
    this->exits = other.exits;
    this->toolCount = other.toolCount;
    this->max_entries_exits = other.max_entries_exits;
    this->max_moves = other.max_moves;

    for (auto const& [id, toolPtr] : other.tools) {
        this->tools[id] = toolPtr->clone();
    }

    if (other.toolInHand != nullptr) {
        int idInHand = other.toolInHand->getID();
        this->toolInHand = this->tools[idInHand];
    } else {
        this->toolInHand = nullptr;
    }
}