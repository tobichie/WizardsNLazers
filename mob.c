#include "include/classes.h"
#include "include/player.h"



struct Player spawnMob() {
    struct Player turtledude = {
        .name = "turtledude",
        .health = 100,
        .mana = 50,
        .strength = 10,
        .intelligence = 10,
        .speed = 30,
        ._class = &Knight,
        .is_bot = 1
    };

    return turtledude;
};