#include "../include/Moby.h"
#include "../include/Game.h"
#include "../include/Macros.h"
#include "../include/Vars.h"

/* This code does the following things:
- It's hooked into a function that should run on every single frame.
- Deletes all plat bolt mobys that are originally part of a level, thereby not touching any mobys we spawn in ourselves.
- Spawns our own platinum bolt mobys to custom coordinates that have been written to memory by patch.txt
- Resets our variables for current bolt_ptrs and slot on death and planet resets.
*/

void _start() {
    *ship_bolt_scale = 1.2;
    *jump_pad_manip = 13.0;

	// Don't run anything if we're on the main menu or in a loading screen.
	if (current_planet == MAIN_MENU)
        return;
	
	// Reset vars if we're on load screen, then don't run the rest of the code until level finishes loading.
	if(should_load == 1 || old_death != death_count)
	{
		memset(bolt_ptrs, 0, 16);
        mobys_deleted = 0;
		
		if(should_load) return;
	}
	
	if(frames_since_spawn < 5)
		return;
		
    // Make electrolyzer bolt 5x larger.
    if (current_planet == DOBBO) {
        *game_bolt_scale = current_weapon == 38 ? 5 : 1;
    }

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