#ifndef SETTINGS_SETTINGS_H
#define SETTINGS_SETTINGS_H

class Settings {
    public:
    class Garden {
    public:
        static const int min_water = 80;
        static const int max_water = 100;
        static const int min_nutrients = 40;
        static const int max_nutrients = 50;
    };
    class WateringCan {
    public:
        static const int capacity = 200;
        static const int dose = 10;
    };
    class Fertilizer {
    public:
        static const int capacity = 100;
        static const int dose = 10;
    };
    class Gardener {
    public:
        static const int max_moves = 10;
        static const int max_entries_exits = 1;
        static const int max_plantings = 2;
        static const int max_harvests = 5;
    };
    class Cactus {
        public:
        static const int water_absorption_percentage = 25;
        static const int nutrient_absorption = 5;
        static const int dies_water_soil_greater = 100;
        static const int dies_water_soil_instants = 3;
        static const int dies_nutrient_soil_less = 1;
        static const int dies_nutrient_soil_instants = 3;
        static const int multiply_nutrient_greater = 100;
        static const int multiply_water_greater = 50;
    };
    class Rose {
        public:
        static const int initial_water = 25;
        static const int initial_nutrients = 25;
        static const int water_loss = 4;
        static const int nutrient_loss = 4;
        static const int water_absorption = 5;
        static const int nutrient_absorption = 8;
        static const int dies_water_less = 1;
        static const int dies_nutrient_less = 1;
        static const int dies_nutrient_greater = 199;
        static const int multiply_nutrient_greater = 100;
        static const int new_nutrients = 25;
        static const int new_water_percentage = 50;
        static const int original_nutrients = 100;
        static const int original_water_percentage = 50;
    };
    class Weed {
        public:
        static const int initial_water = 5;
        static const int initial_nutrients = 5;
        static const int water_absorption = 1;
        static const int nutrient_absorption = 1;
        static const int dies_instants = 60;
        static const int multiply_nutrient_greater = 30;
        static const int multiply_instants = 5;
        static const int new_nutrients = 5;
        static const int original_nutrients = 5;
    };
};

#endif //SETTINGS_SETTINGS_H