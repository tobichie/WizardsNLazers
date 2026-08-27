#ifndef OPTIONS_H
#define OPTIONS_H


struct OPTION {
	int index;
};
void showOptions();
struct Player getOptions();
// all possible options
enum options {
	START_GAME,
	CLASSES,
	AUTHOR
};


#endif
