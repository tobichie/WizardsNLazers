#include <stdio.h>
#include "include/classes.h"
#include "include/player.h"
#include "include/mob.h"



float getAttackDMG(struct Player *attacker) {
	float i = 0;
	return i;
}

void attacks(struct Player *attacker, struct Player *victim, struct Attack *attack){
	// calculate the attackers damage using his strength, the damage type and subtract it from the victim
	// the attacker is first, attacker is decided
	printf("%s attacked %s with %s!\n", attacker->name, victim->name, attack->name);
	// update the attackers mana stat and the opponents hp using the attacks damage adjusted for str and the opponents health adjusted for defense
	// first check if the attacker has the required mp
	if (attacker->mana < attack->mp_req) {
		printf("Couldnt execute the attack due to lacking mana");
		return;
	}
	float str = (float)attacker->strength;
	float adjusted_str = str / 100;
	float adjusted_dmg = (1 + adjusted_str) * attack->dmg;
	attacker->mana -= attack->mp_req;
	victim->health -= adjusted_dmg;
}



struct Attack pickAttack(struct Player *attacker) {
	// get the attack list using the attacks permitted for the attackers class
	int j = 0;
	int id;
	if (attacker->is_bot == 0) {
		switch (attacker->_class->index) { // print all attacks of the class with index 0
			case 0:
				printf("Youre a Knight");
				for (int i = 0; i < KNIGHT_SKILL_COUNT;i++) {
					printf("ID: %d | %s\n", ++j, knight_skills[i]);

				}
				scanf_s("%d", &id);
					// map the index to a knight skill
					switch (id) {
						case 1: return Slash;
						case 2: return Swipe;
						case 3: return Shield_Bash;
					}
				break;
			case 1:
				printf("Youre a Paladin");
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
				printf("Youre a Gunslinger");
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

			default: printf("DEFAULTED"); pickAttack(attacker);	break;

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
		struct Attack attack = pickAttack(first);
		attacks(first, second, &attack);
		struct Attack attack2 = pickAttack(second);
		attacks(second, first, &attack2);
		// return updated health and mana etc
		printf("Name: %s | HP: %f\n", attacker->name, attacker->health);
		printf("Name: %s | HP: %f\n", victim->name, victim->health);
	}
}

struct Player getPlayer() {
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
			    .health = 100.0,
			    .mana = 50.0,
			    .strength = 10,
			    .intelligence = 10,
				.speed = 10,
			    ._class = &Knight,
				.is_bot = 0
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
        			.health = 50,
					.mana = 80,
					.strength = 5,
					.intelligence = 20,
					._class = &Gunslinger,
					.is_bot = 0
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
        		return player;
        	}
	}
	// get the players class and add/deduct stats
	
	// only here for testing will be removed once theres more classes and it will be made a classless option
	struct Player player = {
        	.name = "Steve",
        	.health = 100.0,
			.mana = 50.0,
			.strength = 10,
			.intelligence = 10,
			._class = &Paladin
		};
	
	//yer print all options and their index and then receive the index from the user
	return player;	
}
