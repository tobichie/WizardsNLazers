#include <stdio.h>
#include "include/classes.h"
#include "include/player.h"
#include "include/mob.h"

void fight(struct Player *attacker, struct Player *victim) {

}

void attack(struct Player *attacker, struct Player *victim, struct Attack *attack){
	// calculate the attackers damage using his strength, the damage type and subtract it from the victim
		
	printf("%s attacked %s with %s!", attacker->name, victim->name, attack->name);
}

struct Player getPlayer() {
	showClasses();
	int index;
        printf("Index: ");
        scanf("%d", &index);
	struct CLASS_OPTIONS user_option = {
		.index = --index,
	};
        // printf all options and their index and then receive the index from the user
   	
        enum classes class = user_option.index;
        switch (class) {
		case KNIGHT: 
		{
			//assign the user the knight class
			struct Player player = {
			    .health = 100.0,
			    .mana = 50.0,
			    .strength = 10,
			    .intelligence = 10,
			    ._class = &Knight
			};

			addClass(&player);

			printf(
			    "Health: %.1f\n"
			    "Mana: %.1f\n"
			    "Strength: %d\n"
			    "Intelligence: %d\n"
			    "Class Name: %s\n",
			    player.health,
			    player.mana,
			    player.strength,
			    player.intelligence,
			    player._class->name
			);
			break;
		 }
                case PALADIN:
                {       
	       		//assign the user the knight class
                        struct Player player = { // need to add braces around the case to give each case its own scope
                            .health = 100.0,
                            .mana = 50.0,
                            .strength = 10,
                            .intelligence = 10,
                            ._class = &Paladin
                        };

                        addClass(&player);

                        printf(
                            "Health: %.1f\n"
                            "Mana: %.1f\n"
                            "Strength: %d\n"
                            "Intelligence: %d\n"
                            "Class Name: %s\n",
                            player.health,
                            player.mana,
                            player.strength,
                            player.intelligence,
                            player._class->name
                        );
			break;
		}
	}
	// get the players class and add/deduct stats
	
	// only here for testing will be removed once theres more classes and it will be made a classless option
	struct Player player = {
        	.health = 100.0,
			.mana = 50.0,
			.strength = 10,
			.intelligence = 10,
			._class = &Paladin
		};
	
	//yer print all options and their index and then receive the index from the user
	return player;	
}
