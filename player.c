#include <stdio.h>
#include "include/classes.h"
#include "include/player.h"
#include <Windows.h>
#include <string.h>

#include "include/mob.h"
#include "include/options.h"


float getAttackDMG(struct Player *attacker) {
	float i = 0;
	return i;
}

void attacks(struct Player *attacker, struct Player *victim, struct Attack *attack){
	// calculate the attackers damage using his strength, the damage type and subtract it from the victim
	// the attacker is first, attacker is decided
	// update the attackers mana stat and the opponents hp using the attacks damage adjusted for str and the opponents health adjusted for defense
	// first check if the attacker has the required mp
	if (attacker->mana < attack->mp_req) {
		printf("Couldnt execute the Skill due to lacking mana\n");
		return;
	}
	attacker->mana -= attack->mp_req;
	// Check if its heal first and then add
	if (attack->heal) {
		printf("Skill is heal\n");
		attacker->health += attack->heal; // in the future check what the max health is to not overheal
		return;
	}

	float str = (float)attacker->strength;
	float adjusted_str = str / 100;
	float adjusted_dmg = (1 + adjusted_str) * attack->dmg;
	victim->health -= adjusted_dmg;
	printf("%s attacked %s with %s!\n", attacker->name, victim->name, attack->name);
	printf("%s did %f damage to %s!\n", attack->name, adjusted_dmg, victim->name);

}



struct Attack pickAttack(struct Player *attacker) {
	// get the attack list using the attacks permitted for the attackers class
	int j = 0;
	int id;
	showStats(attacker);
	if (attacker->is_bot == 0) {
		switch (attacker->_class->index) { // print all attacks of the class with index 0
			case 0:
				printf("Youre a Knight\n");
				for (int i = 0; i < KNIGHT_SKILL_COUNT;i++) {
					printf("ID: %d | %s\n", ++j, knight_skills[i]);

				}
				scanf_s("%d", &id);
					// map the index to a knight skill
					switch (id) {
						case 1: return Slash;
						case 2: return Swipe;
						case 3: return Shield_Bash;
						case 4: return Mead;
					}
				break;
			case 1:
				printf("Youre a Paladin\n");
				for (int i = 0; i < PALADIN_SKILL_COUNT;i++) {
					printf("ID: %d | %s\n", ++j, paladin_skills[i]);
				}
				scanf_s("%d", &id);
				// map the index to a knight skill
				switch (id) {
					case 1: return Smite;
					case 2: return Holy_Handgrenade;
					case 3: return Holy_Shield_Bash;
				}
				break;

			case 2:
				printf("Youre a Gunslinger\n");
				for (int i = 0; i < GUNSLINGER_SKILL_COUNT;i++) {
					printf("ID: %d | %s\n", ++j, gunslinger_skills[i]);
				}
				scanf_s("%d", &id);
				// map the index to a knight skill
				switch (id) {
					case 1: return Shoot;
					case 2: return ShootHarder;
					case 3: return Fan;
				}
				break;

			default: printf("DEFAULTED\n"); pickAttack(attacker);	break;

		}
	} else
		switch (attacker->_class->index) { // pick the first attack in the mobs class' attack list
			case 0:
				// Knight
				return Slash;
			case 1:
				// Paladin
				return Smite;
			case 2:
				// gunslinger
				return Shoot;
			default:
				return Shield_Bash;
		}
	return Shield_Bash;
}

void gameLoop(struct Player *player) {
	// start fight, end fight, assign new hp, assign xp, next fight
	struct Player _mob = customOrSet();
	while (player->health >= 0) {
		printf("Starting fight between %s and %s\n", player->name, _mob.name);
		Sleep(2000);
		fight(player, &_mob);
		if (_mob.is_custom == 1) {
			spawnCustomMob();
			return;
		}
		_mob = spawnMob();
	}
	// player died
	int choice;
	printf_s("You died, would you like to restart?\n0 = No\n1 = Yes"); // currently 0 = yes in a lot of code, gotta change that
	scanf_s("%d", &choice);
	switch (choice) {
		case 0: printf("Exiting..."); Sleep(3000); exit(1);
		case 1: struct Player _player = getOptions();gameLoop(&_player);
		default: ;
	}

}


void fight(struct Player *attacker, struct Player *victim) {

	struct Player *first;
	struct Player *second;
	// check speed stat and get random number with biased depending on difference in speed
	if (attacker->speed >= victim->speed) {
		printf("Attacker %s will go first\n", attacker->name);
		first = attacker;
		second = victim;
	}
	else {
		printf("Victim %s will go first\n", victim->name);
		first = victim;
		second = attacker;
	}

	while (attacker->health > 0 && victim->health > 0) {
		// show the players attack options, health and stats and the opponents stats
		// choose an attack from the list of permitted attacks
		if (attacker->health <= 0) {
			printf("%s Won!\n", victim->name);
			break;
		}
		if (victim->health <= 0) {
			printf("%s Won!\n", attacker->name);
			break;
		}
		clear();



		if (attacker->health > 0 && victim->health > 0) {
			struct Attack attack = pickAttack(first);
			attacks(first, second, &attack);
		}
		if (attacker->health > 0 && victim->health > 0) {
			struct Attack attack2 = pickAttack(second);
			attacks(second, first, &attack2);
		}



		// return updated health and mana etc
		printf("Name: %s | HP: %f\n", attacker->name, attacker->health);
		printf("Name: %s | HP: %f\n", victim->name, victim->health);

	}
	if (attacker->health <= 0) {
		printf("The Victor is %s\n", victim->name);
		Sleep(1000);
		return;
	}
	printf("The Victor is %s\n", attacker->name);
	Sleep(3000);
}

struct Player getPlayer() {
	// get name
	char name[NAME_CAP];
	printf("Name: ");
	scanf_s("%49s", name, (unsigned)sizeof(name));
	showClasses();
	int index;
	printf("Index: ");
	scanf_s("%d", &index);
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
			    .health = 100,
			    .mana = 50,
			    .strength = 10,
			    .intelligence = 10,
				.speed = 10,
			    ._class = &Knight,
				.is_bot = 0
			};
			// copy the string into player.name because you cant assign arrays to each other
			strcpy_s(player.name, sizeof(player.name), name);
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
			return player;
		 }
        case PALADIN:
        {
	    //assign the user the knight class
                struct Player player = { // need to add braces around the case to give each case its own scope
                    .health = 100,
                    .mana = 50,
                    .strength = 10,
                    .intelligence = 10,
                    ._class = &Paladin,
					.is_bot = 0
                };

                addClass(&player);
        		strcpy_s(player.name, sizeof(player.name), name);

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
            return player;
		}
        	case GUNSLINGER:
        	{
        		struct Player player = { // need to add braces around the case to give each case its own scope
                	.name = *name,
        			.health = 50,
					.mana = 80,
					.strength = 5,
					.intelligence = 20,
					._class = &Gunslinger,
					.is_bot = 0
				};

        		addClass(&player);
        		strcpy_s(player.name, sizeof(player.name), name);

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
        		return player;
        	}
	        default: ;
        }
	// get the players class and add/deduct stats
	
	// only here for testing will be removed once theres more classes and it will be made a classless option
	const struct Player player = {
        	.name = "Steve",
        	.health = 100,
			.mana = 50,
			.strength = 10,
			.intelligence = 10,
			._class = &Paladin
		};
	
	//yer print all options and their index and then receive the index from the user
	return player;	
}
