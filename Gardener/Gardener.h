#ifndef GARDENER_H
#define GARDENER_H
#include <map>
#include <string>

#include "../Tools/Tool.h"
#include "../Settings/Settings.h"

class Garden;
class Gardener {
    std::map<int, Tool*> tools;
    Tool* toolInHand = nullptr;
    bool has_tool_in_hand = false;

    bool in_garden = false;
    char row, col;

    int toolCount = 0;

    int max_moves = Settings::Gardener::max_moves;
    int moves_this_inst = 0;

    int max_entries_exits = Settings::Gardener::max_entries_exits;
    int entries = 0;
    int exits = 0;
public:
    Gardener() = default;
    ~Gardener();

    void buy(char type);
    void pickUp(int tool_id);
    void drop();
    void listTools() const;

    void moveLeft(Garden* garden);
    void moveRight(Garden* garden);
    void moveUp(Garden* garden);
    void moveDown(Garden* garden);

    Gardener(const Gardener &other);

    void enter(const std::string& pos, Garden* garden);
    void leave(Garden* garden);

    int getRow() const { return row; }
    int getCol() const { return col; }
    bool isInGarden() const { return in_garden; }

    void resetTurn() {
        moves_this_inst = 0;
        entries = 0;
        exits = 0;
    }

    void useTool(Garden* garden);
};

#endif