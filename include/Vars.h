/*--------------------------------------------------
----------------Custom variables <3-----------------
--------------------------------------------------*/

#define NO_CUBOID (0xFFFFFFFF)
#define NULL 0
#define CUSTOM_VAR (0x1BF0000)
#define NUM_BOLTS 4

#define frames_since_death (*(((int*)CUSTOM_VAR) - 8))
#define old_should_load (*(((int*)CUSTOM_VAR) - 7))
// #define ptrs_validated (*(((int*)CUSTOM_VAR) - 6))
#define old_load_type (*(((int*)CUSTOM_VAR) - 5))
#define old_frames (*(((int*)CUSTOM_VAR) - 4))
#define old_gamestate (*(((int*)CUSTOM_VAR) - 3))
#define old_death (*(((int*)CUSTOM_VAR) - 2))
#define mobys_deleted (*(((int*)CUSTOM_VAR) - 1))

// Position for each of the coords, positions are loaded into memory by a lua script
// 4 per bolt, 4 bolts per level, 26 levels
#define coords_array ((float*)0x1BF0000)
// Whether or not each bolt should have a collection animation, also via lua
#define anim_array ((char*)0x1BF0800)
// 4 pointers for each possible bolt we will spawn
#define bolt_ptrs ((Moby**)0x1BF0870)
// #define slot ((char*)0x1BF0880)
#define counter ((int*)0x1BF0884)
#define max_bolts_swapped ((char*)0x1BF0888)
#define spawn_slot_debug ((char*)0x1BF088C)
#define copy_max_bolts_table ((int*)0x1BF0890)
		