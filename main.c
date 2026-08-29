#include <stdio.h>

#include "include/mob.h"
#include "include/options.h"
#include "include/player.h"


int main(void) 
{
	struct Player _player = getOptions();
	struct Player _mob = spawnMob();
	fight(&_player, &_mob);

	return 0;
}

