import struct
import os

# Fill in known data
locations = {
    #----LEVEL 1 - OOZLA----#
    1:  [
    (290, 415, 116.0, 0), 
    (292, 415, 116.0, 0), 
    (294, 415, 116.0, 0), 
    (296, 415, 116.0, 0), 
    ],
    #----LEVEL 2 - MAKTAR----#
    2:  [
    (498, 326, 118, 1),
    (500, 326, 118, 1),
    (502, 326, 118, 1),
    (504, 326, 118, 1),
    ],
    #----LEVEL 3 - ENDAKO----#
    3:  [
    (297, 234, 130, 0), 
    (299, 234, 130, 0), 
    (301, 234, 130, 0), 
    (303, 234, 130, 0), 
    ],
    #----LEVEL 4 - BARLOW----#
    4:  [
    (284, 294, 52, 1), 
    (284, 296, 52, 1), 
    (284, 298, 52, 1), 
    (284, 300, 52, 1), 
    ],
    #----LEVEL 5 - FELTZIN----#
    5:  [
    (444.2, 571.7, 535.8, 1),
    ],
    #----LEVEL 6 - NOTAK----#
    6:  [
    (272, 171, 60, 1),
    (271, 173, 60, 1), 
    (269, 175, 60, 1), 
    (267, 178, 60, 1),
    ],
    #----LEVEL 7 - SIBERIUS----#
    7:  [
    (522.6, 323.6, 223.0, 0), 
    (418.7, 704.3, 201.4, 0),
    (337.7, 696.7, 229.9, 1),
    ],
    #----LEVEL 8 - TABORA----#
    8:  [
    (565.0, 346.9, 182.5, 1), 
    (653.7, 259.6, 170.8, 0), 
    (583.6, 244.1, 146.6, 1)],
    #----LEVEL 9 - DOBBO----#
    9:  [
    (420.9, 183.1, 320.4, 1), 
    (372.6, 238.3, 409.4, 0),
    (483.6, 268.5, 434.1, 1)
    ],
    #----LEVEL 10 - HRUGIS----#
    10:  [
    (678.0, 572.7, 445.4, 1),
    ],
    #----LEVEL 11 - JOBA----#
    11: [
    (420.6, 418.36, 100.23, 1), 
    (416.37, 592.31, 179.78, 1),
    (389.3, 467.0, 110.2, 1),
    (509.8, 351.0, 120.5, 1)
    ],
    #----LEVEL 12 - TODANO----#
    12: [
    (282.5, 190.1, 186.1, 1), 
    (263.3, 343.7, 158.5, 0),
    (214.0, 210.5, 164.5, 0),
    (346.9, 273.0, 160.7, 1)
    ],
    #----LEVEL 13 - BOLDAN----#
    13: [
    (317.9, 148.9, 120.4, 0), 
    (491.8, 290.2, 65.6, 1), 
    (118.2, 249.0, 128.7, 1),
    (213.7, 321.15, 136.4, 1)
    ],
    #----LEVEL 14 - A2----#
    14: [
    (328.4, 197.4, 119.5, 0),
    (406.6, 397.5, 137.0, 0),
    (353.0, 195.6, 142.4, 1)
    ],
    #----LEVEL 15 - GORN----#
    15:  [
    (388.6, 440.8, 593.0, 1),
    ],
    #----LEVEL 16 - SNIVELAK----#
    16: [
    (517.8, 490.4, 142.3, 1),
    (334.1, 567.7, 146.9, 1)
    ],
    #----LEVEL 17 - SMOLG----#
    17: [
    (415.1, 477.8, 173.9, 1), 
    (448.5, 368.0, 91.3, 1),
    (94.8, 364.0, 165.2, 0)
    ],
    #----LEVEL 18 - DAMOSEL----#
    18: [
    (586.9, 353.7, 120.1, 1), 
    (377.9, 229.5, 141.5, 1),
    (479.0, 484.16, 121.9, 1),
    (651.6, 487.5, 133.8, 1)
    ],
    #----LEVEL 19 - GRELBIN----#
    19: [
    (315.1, 262.6, 581.8, 1), 
    (256.5, 278.4, 329.4, 1), 
    (366.8, 371.9, 313.0, 0)
    ],
    #----LEVEL 20 - YEEDIL----#
    20: [
    (389.0, 297.1, 136.8, 1), 
    (815.9, 542.9, 397.0, 1),
    (173.8, 649.9, 362.1, 1)
    ],
    #----LEVEL 26 - JAMMING ARRAY---#
    26: [ 
    (584.3, 200.1, 466.4, 1)
    ]
}

TOTAL_PLANETS = 27   # 0 through 26
SLOTS_PER_PLANET = 4

root_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
bin_dir = os.path.join(root_dir, "bin")

os.makedirs(bin_dir, exist_ok=True)

coords_out = open(os.path.join(bin_dir, "coords.bin"), "wb")
anims_out = open(os.path.join(bin_dir, "anims.bin"), "wb")

used_bolts = 0
for planet_id in range(TOTAL_PLANETS):
    slots = locations.get(planet_id, [])
    
    for slot_index in range(SLOTS_PER_PLANET):
        if slot_index < len(slots):
            used_bolts += 1
            x, y, z, skip = slots[slot_index]
        else:
            x = y = z = 0.0
            skip = 0
        
        # Write 4 floats for coords: x, y, z, 0.0 in big endian.
        coords_out.write(struct.pack('>ffff', x, y, z, 0.0))
        # Write 1 byte for anim flag
        anims_out.write(struct.pack('B', skip))

coords_out.close()
anims_out.close()

print("Generated coords.bin and anims.bin with:")
print(f"- {used_bolts} total entries")
print(f"- {TOTAL_PLANETS * SLOTS_PER_PLANET * 16} bytes for coords")
print(f"- {TOTAL_PLANETS * SLOTS_PER_PLANET} bytes for anims")

# Create maxbolts.bin for levels 0–20 (level 2 (Maktar) includes level 26 (Jamming Array)
bolt_counts = []
for level in range(21):
    count = 0
    if level in locations:
        count += len(locations[level])
    if level == 2 and 26 in locations:
        count += len(locations[26])
    bolt_counts.append(count)

maxbolts_path = os.path.join(bin_dir, "maxbolts.bin")
with open(maxbolts_path, "wb") as f:
    for count in bolt_counts:
        f.write(struct.pack(">I", count))

print(f"Generated maxbolts.bin with:")
print(f"- Total bytes: {21 * 4}")
