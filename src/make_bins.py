import struct, os, argparse, importlib

parser = argparse.ArgumentParser()
parser.add_argument('--test', action='store_true')
parser.add_argument('--s', action='store_true')
args = parser.parse_args()

locations = importlib.import_module('test_coords' if args.test else 'coords').locations

TOTAL_PLANETS = 27
SLOTS_PER_PLANET = 4

root_dir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
bin_dir = os.path.join(root_dir, "bin")
os.makedirs(bin_dir, exist_ok=True)

with open(os.path.join(bin_dir, "coords.bin"), "wb") as coords_out, \
     open(os.path.join(bin_dir, "anims.bin"), "wb") as anims_out:

    used_bolts = 0
    for planet_id in range(TOTAL_PLANETS):
        slots = locations.get(planet_id, [])
        for i in range(SLOTS_PER_PLANET):
            if i < len(slots):
                x, y, z, skip = slots[i]
                used_bolts += 1
            else:
                x = y = z = 0.0
                skip = 0
            coords_out.write(struct.pack('>ffff', x, y, z, 0.0))
            anims_out.write(struct.pack('B', skip))

print(f"{'[TEST] ' if args.test else ''}Generating coords/anims with {used_bolts} entries...")

bolt_counts = [
    len(locations.get(lvl, [])) + (len(locations.get(26, [])) if lvl == 2 else 0)
    for lvl in range(21)
]

with open(os.path.join(bin_dir, "maxbolts.bin"), "wb") as f:
    for count in bolt_counts:
        f.write(struct.pack(">I", count))