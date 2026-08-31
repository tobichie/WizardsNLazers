#include <stdio.h>

#include "include/mob.h"
#include "include/options.h"
#include "include/player.h"


int main(void) 
{
	struct Player _player = getOptions();
	// check if I want to use a custom mob or standard mobs lineup
	struct Player _mob = customOrSet();
	printf("Starting fight between %s and %s", _player.name, _mob.name);
	fight(&_player, &_mob);

	return 0;
}

