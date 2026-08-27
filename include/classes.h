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
	
};

extern struct Class Knight;
extern struct Class Paladin;

#endif

