CC = powerpc64-linux-gnu-gcc
CFLAGS = -mcpu=cell -mbig -m32 -nostdlib -O0
PATCH_FILE = patch.txt

# Function to extract the target address from patch.txt
define get_addr
$(shell grep -i "bin/$1.bin" $(PATCH_FILE) | cut -d':' -f1)
endef

SRC_DIR = src/
BIN_DIR = bin/

SRCS = $(wildcard $(SRC_DIR)*.c)
BINS = $(SRCS:$(SRC_DIR)%.c=$(BIN_DIR)%.bin)

all: clean $(BIN_DIR) $(BINS) run_python-s

test: clean $(BIN_DIR) $(BINS) run_python-test

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)%.bin: $(SRC_DIR)%.c
	@echo "Building $(@F) from $<..."
	ADDR=$(call get_addr,$*) && \
	$(CC) $(CFLAGS) -Wl,--oformat=binary,-Ttext=$$ADDR -o $@ $<

clean:
	rm -rf $(BIN_DIR)

run_python-%:
	python3 $(SRC_DIR)/make_bins.py --$*
	rm -rf  $(SRC_DIR)__pycache__