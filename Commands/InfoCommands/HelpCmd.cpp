#include "HelpCmd.h"
#include <iostream>

bool HelpCmd::execute(std::istringstream &args) {
    std::string extra_args;
    if (args >> extra_args) {
        std::cout << "Error. The command does not accept arguments." << std::endl;
        return false;
    }

    std::cout << "--- Available Commands ---\n";
    std::cout << " GARDEN CREATION:\n";
    std::cout << "  garden <rows> <cols>    : Create a garden with specified dimensions (min 3 cells total).\n";
    std::cout << "\n MOVEMENT:\n";
    std::cout << "  up                      : Move the gardener up.\n";
    std::cout << "  down                    : Move the gardener down.\n";
    std::cout << "  left                    : Move the gardener left.\n";
    std::cout << "  right                   : Move the gardener right.\n";
    std::cout << "  enter <pos>             : Gardener enters the garden at position <pos> (e.g., 'enter aa').\n";
    std::cout << "  leave                   : Gardener leaves the garden.\n";
    std::cout << "\n ACTIONS:\n";
    std::cout << "  plant <pos> <type>      : Plant a seed at <pos>. Types: c (Cactus), r (Rose), e (Weed), x (Exotic).\n";
    std::cout << "  harvest <pos>           : Harvest the plant at <pos>.\n";
    std::cout << "  buy <type>              : Buy a tool. Types: g (Watering Can), a (Fertilizer), t (Shears), z (ToolZ).\n";
    std::cout << "  pickup <id>             : Pick up a tool with <id>.\n";
    std::cout << "  drop                    : Drop the tool currently in hand.\n";
    std::cout << "\n INFORMATION:\n";
    std::cout << "  listarea                : List objects in the garden area.\n";
    std::cout << "  listtools               : List tools owned by the gardener.\n";
    std::cout << "  listplant <pos>         : List details of the plant at <pos>.\n";
    std::cout << "  listplants              : List all plants in the garden.\n";
    std::cout << "  listsoil <pos> [radius] : List soil and objects around <pos> within [radius] (default 1).\n";
    std::cout << "\n TIME:\n";
    std::cout << "  advance [n]             : Advance time by [n] instants (default 1).\n";
    std::cout << "\n SYSTEM:\n";
    std::cout << "  save <name>             : Save the current state with <name>.\n";
    std::cout << "  load <name>             : Load a saved state with <name>.\n";
    std::cout << "  delete <name>           : Delete a saved state with <name>.\n";
    std::cout << "  execute <filename>      : Execute commands from a file.\n";
    std::cout << "  exit                    : Exit the simulator.\n";
    std::cout << "  help                    : Show this help message.\n";
    std::cout << "--------------------------\n";

    return true;
}