#include "../include/Moby.h"
#include "../include/Game.h"
#include "../include/Macros.h"
#include "../include/Vars.h"

/* This code does the following things:
- It's hooked into a function that should run on every single frame.
- Deletes all plat bolt mobys that have a UID assigned (essentially plat bolts that were originally placed in the level).
- Spawns our own platinum bolt mobys to custom coordinates that have been written to memory by racman patch.
- Resets our variables for current bolt_ptrs on death and planet resets.
*/

void _start() {
    *ship_bolt_scale = 1.2;
	*jump_pad_accel = 13.0;
    *game_bolt_scale = current_weapon == 38 ? 5 : 1; // Make electrolyzer bolt 5x larger.

	if (current_planet == MAIN_MENU)
        return;
	
	if(should_load == 1 || old_death != death_count)
	{
		memset(bolt_ptrs, 0, 16);
        mobys_deleted = 0;
		
		if(should_load) return;
	}
	
	if(frames_since_spawn < 5)
		return;
		

	// Delete existing platinum bolt mobys!
    if (mobys_deleted < 20 && !ship_level) {
        get_moby_with_oclass(0x46e, moby) {
            mobys_deleted += 1;
            despawn_moby(moby);
        }
    }


    // Spawn in our own bolt mobys!
    for (int i = 0; i < 4; i++) {
        if (!bolt_collected(current_planet, i) && !is_ptr_valid(bolt_ptrs[i]) && coords_for_bolt(current_planet, i)[0] != NULL) {
            Moby* bolt = spawn_bolt_macro(coords_for_bolt(current_planet, i), i, NO_CUBOID, NO_CUBOID);
            if (!bolt || bolt->oClass != oclass_macro) continue; // just try again i guess?
            bolt_ptrs[i] = bolt;

            BoltVars* vars = bolt->pVar;
            vars->skip_animation = animation_for_bolt(current_planet, i);
                        
            bolt->updateDistance = 255; 
            bolt->drawDistance = 32767;
        }
	}

    old_death = death_count;
} 