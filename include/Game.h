/*--------------------------------------------------
---------------------Functions----------------------
--------------------------------------------------*/

#define memcpy ((void (*)(void*, void*, int))0x119a97c)
#define memset ((void (*)(void*, char, int))0x011a4fec)

// Spawn plat bolt on a normal level (0x46e). arg: coords, pos in array, cuboid id, cuboid id
#define spawn_game_bolt ((Moby* (*)(float*, unsigned int, unsigned int, unsigned int))0x0ccbe40)
// Spawn plat bolt on a ship level (0x126c): coords, pos in array, cuboid id, cuboid id
#define spawn_ship_bolt ((Moby* (*)(float*, unsigned int, unsigned int, unsigned int))0x0020f40)

// Sets moby's state to -3, effectively despawning it. arg: moby ptr
#define despawn_moby ((void (*)(Moby*))0xb575ec)


/*--------------------------------------------------
---------------------Variables----------------------
--------------------------------------------------*/

// Gamestate vars
#define INGAME 0
#define CINEMATIC 1
#define IN_LEVEL_MOVIE 2
#define PAUSED 3
#define LOADING 6

//Weapons
#define ELECTROLYZER 38

// player coords
#define player_coords ((float*)0x147F260)


// 4 bytes per planet indexed by planet ID 
#define collected_bolts_array ((char*)0x1562540)
#define game_max_bolts_table ((int*) 0x013453f8) 

// Game variables.
#define frames_since_spawn (*((int*)0x1480470))
#define death_count (*((int*)0x1569774))
#define gamestate (*((int*)0x156B064))
#define player_state (*((int*)0x1481474))
#define current_planet (*((int*)0x1329A3C))
#define current_weapon (*((int*)0x14814C4))

#define game_bolt_scale ((float*)0x01373EA0)
#define ship_bolt_scale ((float*)0x013182A0)
#define jump_pad_manip ((float*)0x13185B8)

#define load_screen_count (*((int*)0x147A258))
#define load_screen_type (*((int*)0x147A254))

#define should_load (*((int*)0x156B050))
#define planet_to_load (*((int*)0x156B054))


#define MAIN_MENU -1
#define ARANOS_TUTORIAL 0
#define OOZLA 1
#define MAKTAR 2
#define ENDAKO 3
#define BARLOW 4
#define FELTZIN 5
#define NOTAK 6
#define SIBERIUS 7
#define TABORA 8
#define DOBBO 9
#define HRUGIS 10
#define JOBA 11
#define TODANO 12
#define BOLDAN 13
#define ARANOS_REVISIT 14
#define GORN 15
#define SNIVELAK 16
#define SMOLG 17
#define DAMOSEL 18
#define GRELBIN 19
#define YEEDIL 20
#define MUSEUM 21
#define DOBBO_ORBIT 22
#define DAMOSEL_ORBIT 23
#define SHIP_SHACK 24
#define WUPASH 25
#define JAMMING_ARRAY 26