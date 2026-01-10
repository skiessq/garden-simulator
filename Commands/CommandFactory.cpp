#include "CommandFactory.h"
#include "TimeCommands/AdvanceCmd.h"
#include "ActionCommands/HarvestCmd.h"
#include "ActionCommands/BuyCmd.h"
#include "ActionCommands/DropCmd.h"
#include "ActionCommands/PlantCmd.h"
#include "ActionCommands/PickUpCmd.h"
#include "GeneralCommands/DeleteCmd.h"
#include "GeneralCommands/ExecuteCmd.h"
#include "GeneralCommands/ExitCmd.h"
#include "GeneralCommands/SaveCmd.h"
#include "GeneralCommands/GardenCmd.h"
#include "GeneralCommands/LoadCmd.h"
#include "InfoCommands/ListAreaCmd.h"
#include "InfoCommands/ListToolsCmd.h"
#include "InfoCommands/ListPlantCmd.h"
#include "InfoCommands/ListPlantsCmd.h"
#include "InfoCommands/ListSoilCmd.h"
#include "MovementCommands/DownCmd.h"
#include "MovementCommands/UpCmd.h"
#include "MovementCommands/EnterCmd.h"
#include "MovementCommands/LeaveCmd.h"
#include "MovementCommands/RightCmd.h"
#include "MovementCommands/LeftCmd.h"

#include "InfoCommands/HelpCmd.h"

Command* createCommand(const std::string &name) {
    if (name == "advance") return new AdvanceCmd();
    if (name == "help") return new HelpCmd();

    if (name == "harvest") return new HarvestCmd();
    if (name == "buy") return new BuyCmd();
    if (name == "drop") return new DropCmd();
    if (name == "plant") return new PlantCmd();
    if (name == "pickup") return new PickUpCmd();

    if (name == "delete") return new DeleteCmd();
    if (name == "execute") return new ExecuteCmd();
    if (name == "exit") return new ExitCmd();
    if (name == "save") return new SaveCmd();
    if (name == "garden") return new GardenCmd();
    if (name == "load") return new LoadCmd();

    if (name == "listarea") return new ListAreaCmd();
    if (name == "listtools") return new ListToolsCmd();
    if (name == "listplant") return new ListPlantCmd();
    if (name == "listplants") return new ListPlantsCmd();
    if (name == "listsoil") return new ListSoilCmd();

    if (name == "down") return new DownCmd();
    if (name == "up") return new UpCmd();
    if (name == "enter") return new EnterCmd();
    if (name == "leave") return new LeaveCmd();
    if (name == "right") return new RightCmd();
    if (name == "left") return new LeftCmd();

    return nullptr;
}