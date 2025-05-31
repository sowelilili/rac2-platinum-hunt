/*--------------------------------------------------
---------------------Macros <3 <3-------------------
--------------------------------------------------*/

#define coords_for_bolt(planetId, slot) \
    (&coords_array[4 * (planetId * 4 + slot)])

#define animation_for_bolt(planetId, slot) \
    (anim_array[4 * planetId + slot])

#define bolt_collected(planetId, slot) \
    (collected_bolts_array[planetId * 4 + slot])

#define moby_is_active(state) \
    ((state != 0xFE) && (state != 0xFD))
	
// Macro for checking for any moby with a non-zero UID, and activated state (1)
#define get_moby_with_oclass(o_class_value, moby_var)                  \
    for (Moby* moby_var = moby_instance_table; moby_var <= moby_instance_perm_end; ++moby_var)   \
        if (moby_var->state > 0 && moby_var->oClass == (o_class_value) && (moby_var)->UID != 0)

#define ship_level (current_planet == FELTZIN || current_planet == HRUGIS || current_planet == GORN)

// Choose between the two functions based on level ID
#define spawn_bolt_macro (ship_level ? spawn_ship_bolt : spawn_game_bolt)

#define oclass_macro (ship_level ? 0x126c : 0x46e)

#define is_ptr_valid(moby) (moby && moby->oClass == oclass_macro)