#include "include/classes.h"
#include "include/player.h"



struct Player spawnMob() {
    struct Player turtledude = {
        .health = 100.0,
        .mana = 50.0,
        .strength = 10,
        .intelligence = 10,
        .speed = 30,
        ._class = &Knight,
        .is_bot = 1
    };

    return turtledude;
};