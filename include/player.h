#ifndef PLAYER_H
#define PLAYER_H
#define NAME_CAP 50
struct Player {
        char name[NAME_CAP];
        double health;
        double mana;
        int strength;
        int intelligence;
        int speed;
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
        double dmg;
        enum damageType type;

};
void fight(struct Player *attacker, struct Player *victim);


#endif
