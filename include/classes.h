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
	
};

extern struct Class Knight;
extern struct Class Paladin;
// classes to be added
extern struct Class Gunslinger;
extern struct Class Wizard;
extern struct Class Sorcerer; // because theres a huge difference
extern struct Class Alchemist;

#endif

