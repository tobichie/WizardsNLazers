#include <stdio.h>
#include "./include/options.h"
#include "./include/player.h"


const char *option_names[] = {
    "START_GAME",
    "CLASSES",
    "AUTHOR"
};

void showOptions()
{
	// function that prints all options aswell as their index by going through the options enum
	for (int i = 0; i <= AUTHOR; i++) {
		printf("ID:%d%s\n", (i+1) , option_names[i]);
	}
}


// function that returns the option the user chooses
struct Player getOptions()
{
	clear();   
	showOptions();
	int index;
	printf("Index: ");
	scanf("%d", &index);
	struct OPTION user_option = {
		.index = --index, 
	};
	// print all options and their index and then receive the index from the user
	//
	enum options option = user_option.index;
	switch (option) {
		case START_GAME:
			printf("Starting Game\n");
			// next we get the users class and initialize the character
			struct Player player = getPlayer();
			return player;
			
		case CLASSES:
			printf("Showing Classes\n");
			getOptions();
			break;
		case AUTHOR:
			printf("Author is me. great god bai lin\n");
			getOptions();
			break;
	}
	
	
}


