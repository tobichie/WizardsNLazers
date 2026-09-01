#include <stdio.h>
#include <string.h>

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

// for testing

struct Player spawnCustomMob() {
    char name[NAME_CAP];
    float health;
    float mana;
    int strength;
    int intelligence;
    int speed;

    int choice;
    printf("Would you like to set all stats at once?\n0 = Yes\n1 = No\n");
    scanf_s("%d", &choice);

    if (choice == 0) {
        int int_stats;

        printf("Set stats to...: ");
        scanf_s("%d", &int_stats);
        float float_stats = (float) int_stats;
        // next assign the number to each of the stats
        health = float_stats;
        mana = float_stats;
        strength = int_stats;
        intelligence = int_stats;
        speed = int_stats;
    } else {
        printf("Health: ");
        scanf_s("%f", &health);
        printf("Mana: ");
        scanf_s("%f", &mana);
        printf("Strength: ");
        scanf_s("%d", &strength);
        printf("Intelligence: ");
        scanf_s("%d", &intelligence);
        printf("Speed: ");
        scanf_s("%d", &speed);
    }

    printf("Name: ");
    scanf_s("%s", name, (unsigned)sizeof(name));


    struct Player turtledude = {
        .health = health,
        .mana = mana,
        .strength = strength,
        .intelligence = intelligence,
        .speed = speed,
        ._class = &Knight,
        .is_bot = 1,
        .is_custom = 1
    };
    strcpy_s(turtledude.name, sizeof(turtledude.name), name);
    printf("Sending %s to the Arena\n", turtledude.name);
    return turtledude;
};

struct Player customOrSet() {
    int choice;
    printf("Would you like to fight a random lineup of mobs or create custom ones\n0 = Custom\n1 = Normal\n"); // currently not random

    scanf_s("%d", &choice);

    switch (choice) {
        case 0: return spawnCustomMob();
        case 1: return spawnMob();
    }
}