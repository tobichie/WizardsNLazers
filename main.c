#include <stdio.h>

#include "include/mob.h"
#include "include/options.h"
#include "include/player.h"


int main(void) 
{
	struct Player _player = getOptions();
	// check if I want to use a custom mob or standard mobs lineup
	gameLoop(&_player);

	return 0;
}

