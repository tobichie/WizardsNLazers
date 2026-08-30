#include <stdio.h>
#include "./include/classes.h"
#include "./include/player.h"

const char *class_names[] = {
        "KNIGHT",
        "PALADIN"
};

void showClasses()
{
	for (int i = 0; i<= PALADIN; i++) {
		printf("ID:%d | %s\n", (i + 1), class_names[i]);
	}
}

// struct for Classes
// Attack information should ideally be read from a file in the future

// KNIGHT -----------------------------

struct Class Knight = {
	.name = "Knight",
	.index = 0,
	.add_hp = 20,
	.add_mp = 10,
	.add_str = 30,
	.add_int = 10
};

// KNIGHT END ________________

// PALADIN -----------------------------

struct Class Paladin = {
    .name = "Paladin",
	.index = 1,
    .add_hp = 30,
    .add_mp = 15,
    .add_str = 20,
    .add_int = 20
};

static struct Attack Smite = {
	.name = "Smite",
	.dmg = 30,
	LIGHT,
	0.8,
	0
};
static struct Attack Holy_Handgrenade = {
	.name = "Holy Handgrenade",
	.dmg = 30,
	.type = HEAVY,
	.accuracy = 0.7,
	.mp_req = 10

};
static struct Attack Holy_Shield_Bash = {
	.name = "Holy Shield Bash",
	.dmg = 80,
	.type = MID,
	.accuracy = 0.6,
	.mp_req = 8

};
// PALADIN END ________________

// GUNSLINGER -----------------------------

struct Class Gunslinger = {
	.name = "Gunslinger",
	.index = 2,
	.add_hp = 30,
	.add_mp = 15,
	.add_str = 20,
	.add_int = 20
};
// char array of attack names is stored in classes.h along with the enum
static struct Attack Shoot = {
	.name = "Shoot",
	.dmg = 30,
	LIGHT,
	0.8,
	0
};
static struct Attack ShootHarder = {
	.name = "Shoot harder",
	.dmg = 30,
	HEAVY,
	0.7,
	10

};
static struct Attack Fan = {
	.name = "Fan",
	.dmg = 80,
	MID,
	0.6,
	8

};


// GUNSLINGER END ________________
struct Class Wizard;
struct Class Sorcerer; // because theres a huge difference
struct Class Alchemist;

void addClass(struct Player *player){
	player->health += player->_class->add_hp;
	player->mana += player->_class->add_mp;
	player->strength += player->_class->add_str;
	player->intelligence += player->_class->add_int;
}
