#ifndef CLASSES_H
#define CLASSES_H
#ifndef NAME_CAP
#define NAME_CAP 50
#endif
struct CLASS_OPTIONS  {
	int index;
};
void addClass();
void showClasses();
struct Player getPlayer();
// all possible options
enum classes {
        KNIGHT,
        PALADIN,

};

// struct for Classes
struct Class {
	char name[NAME_CAP];
        int index;
	float add_hp;
	float add_mp;
	int add_str;
	int add_int;
	int add_spd;
	int defense;
};

extern struct Class Knight;
enum KnightSkills {
	SLASH,
	SWIPE,
	SHIELD_BASH,
	KNIGHT_SKILL_COUNT
};
const char *knight_skills[] = {
	"Slash",
	"Swipe",
	"Shield Bash"
};
extern struct Attack Slash;
extern struct Attack Swipe;
extern struct Attack Shield_Bash;


extern struct Class Paladin;
enum PaladinSkills {
	SMITE,
	HOLY_HANDGRENADE,
	HOLY_SHIELD_BASH, //idk
	PALADIN_SKILL_COUNT
};
const char *paladin_skills[] = {
	"Smite",
	"Holy Handgrenade",
	"Holy Shield Bash"
};
extern struct Attack Smite;
extern struct Attack Holy_Handgrenade;
extern struct Attack Holy_Shield_Block;
// classes to be added
extern struct Class Gunslinger;
enum GunslingerSkills {
	SHOOT,
	SHOOT_HARDER,
	FAN,
	GUNSLINGER_SKILL_COUNT
};
const char *gunslinger_skills[] = {
	"Shoot",
	"Shoot Harder",
	"Fan"
};
extern struct Attack Shoot;
extern struct Attack ShootHarder;
extern struct Attack Fan;

extern struct Class Wizard;
extern struct Class Sorcerer; // because theres a huge difference
extern struct Class Alchemist;

#endif

