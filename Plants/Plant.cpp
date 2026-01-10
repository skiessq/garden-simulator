#include "Plant.h"
#include "Type/Cactus.h"
#include "Type/Weed.h"
#include "Type/ExoticPlant.h"
#include "Type/Rose.h"

Plant::Plant(char s, int w, int n, std::string b)
    : symbol(s), water(w), nutrients(n), beauty(b)
{}


Plant* Plant::create(char symbol) {
    switch (symbol) {
        case 'c':
            return new Cactus();
        case 'e':
            return new Weed();
        case 'r':
            return new Rose();
        case 'x':
            return new ExoticPlant();
        default:
            return nullptr;
    }
}
