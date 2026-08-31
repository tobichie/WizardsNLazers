#pragma once
#ifndef _WIN64
#define clear() printf("\033[H\033[J")
#else
#define clear() printf("\033[2J")
#endif

#ifndef PLAYER_H
#define PLAYER_H
#define NAME_CAP 50

struct Player {
        char name[NAME_CAP];
        float current_health; // gets updated during match and used as a reference when increasing health
        float health;
        float current_mana;
        float mana;
        int strength;
        int intelligence;
        int speed;
        int stunned;
        int level;
        float xp;
        struct Class *_class;
        int is_bot;
};
struct Player getPlayer();
enum damageType {
        LIGHT,
        MID,
        HEAVY,

};



// all mobs are initialized as players

struct Attack {
        char name[NAME_CAP];
        float dmg;
        enum damageType type;
        float accuracy;
        float mp_req;
};
void fight(struct Player *attacker, struct Player *victim);


#endif
