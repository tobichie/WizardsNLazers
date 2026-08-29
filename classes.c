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

struct Class Knight = {
	.name = "Knight",
	.index = 0,
	.add_hp = 20,
	.add_mp = 10,
	.add_str = 30,
	.add_int = 10
};
struct Class Paladin = {
        .name = "Paladin",
	.index = 0,
        .add_hp = 30,
        .add_mp = 15,
        .add_str = 20,
        .add_int = 20
};

struct Class Gunslinger;
struct Class Wizard;
struct Class Sorcerer; // because theres a huge difference
struct Class Alchemist;

void addClass(struct Player *player){
	player->health += player->_class->add_hp;
	player->mana += player->_class->add_mp;
	player->strength += player->_class->add_str;
	player->intelligence += player->_class->add_int;
}
