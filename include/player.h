#ifndef PLAYER_H
#define PLAYER_H
#define NAME_CAP 50
struct Player {
        char name[NAME_CAP];
        float health;
        float mana;
        int strength;
        int intelligence;
        int stunned;
        struct Class *_class;
};
struct Player getPlayer(void);
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

};


#endif
