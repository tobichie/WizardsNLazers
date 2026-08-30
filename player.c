#include <stdio.h>
#include "include/classes.h"
#include "include/player.h"
#include "include/mob.h"



double getAttackDMG(struct Player *attacker) {

}

void attacks(struct Player *attacker, struct Player *victim, struct Attack *attack){
	// calculate the attackers damage using his strength, the damage type and subtract it from the victim
	// the attacker is first, attacker is decided
	printf("%s attacked %s with %s!", attacker->name, victim->name, attack->name);
	// update the attackers mana stat and the opponents hp using the attacks damage adjusted for str and the opponents health adjusted for defense

}



struct Attack pickAttack(struct Player *attacker) {
	// get the attack list using the attacks permitted for the attackers class
	int j = 0;
	if (attacker->is_bot == 0) {
		switch (attacker->_class->index) { // print all attacks of the class with index 0
			case 0:
				enum KnightSkills skills;
				for (int i = 0; i < KNIGHT_SKILL_COUNT;i++) {
					printf("ID: %d | %s", ++j, knight_skills[i]);
				}
			case 1:
				enum PaladinSkills skills1;
				for (int i = 0; i < GUNSLINGER_SKILL_COUNT;i++) {
					printf("ID: %d | %s", ++j, paladin_skills[i]);
				}
			case 2:
				for (int i = 0; i < GUNSLINGER_SKILL_COUNT;i++) {
					printf("ID: %d | %s", ++j, gunslinger_skills[i]);
				}
			default: ;
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
}

void fight(struct Player *attacker, struct Player *victim) {
	struct Player *first;
	struct Player *second;
	// check speed stat and get random number with biased depending on difference in speed
	if (attacker->speed >= victim->speed) {
		printf("Attacker %s will go first", attacker->name);
		first = attacker;
		second = victim;
	}
	else {
		printf("Victim %s will go first", victim->name);
		first = victim;
		second = attacker;
	}

	while (attacker->health > 0 && victim->health > 0) {
		// show the players attack options, health and stats and the opponents stats
		// choose an attack from the list of permitted attacks
		struct Attack attack = pickAttack(first);
		attacks(first, second, &attack);
		struct Attack attack2 = pickAttack(second);
		attacks(second, first, &attack);
		// return updated health and mana etc

	}
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
				.speed = 10,
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
