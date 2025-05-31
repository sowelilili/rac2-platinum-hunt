/*--------------------------------------------------
----------------Custom variables <3-----------------
--------------------------------------------------*/

#define NO_CUBOID (0xFFFFFFFF)
#define NULL 0
#define CUSTOM_VAR (0x1BF0000)
#define NUM_BOLTS 4

#define mobys_deleted (*(((int*)CUSTOM_VAR) - 1))
#define old_death (*(((int*)CUSTOM_VAR) - 2))

// Position for each of the coords, positions are loaded into memory by patch.txt
// 4 bytes per bolt, 4 bolts per level, 26 levels
#define coords_array ((float*)0x1BF0000)

// Whether or not each bolt should have a collection animation, also via patch.txt
// 1 byte per bolt, 4 bolts per level, 26 levels
#define anim_array ((char*)0x1BF0800)

// 4 pointers for each possible bolt we will spawn
#define bolt_ptrs ((Moby**)0x1BF0870)
