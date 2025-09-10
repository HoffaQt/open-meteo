# --- Basvariabler --
CC 		 ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -O2 -MMD -MP
SRC := $(wildcard src/*.c)
MODE ?= release

ifeq ($(MODE),debug)
 CFLAGS += -g -O0
 OUTDIR := build/debug
else
 OUTDIR := build/release
endif

OBJ := $(patsubst src/%.c, $(OUTDIR)/%.o, $(SRC)) # TODO: mappa src/%.c -> build/%.o
BIN := $(OUTDIR)/app
DEP := $(OBJ:.o=.d) # TODO: mappa build/%.o -> build/%.d

# --- Standardmål --
all: $(BIN)

$(BIN): $(OBJ)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@
				
$(OUTDIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c  $< -o $@ -MF $(basename $@).d -MT $@

				
 # --- Kompilering (mönsterregel) --
# TODO: skapa build/ om den saknas; kompilera src/%.c till build/%.o
 # TODO: (sen) skriv .d-filer till rätt plats med -MF och rätt mål med -MT
 # --- Städning --
clean:
	$(RM) -r build
	
-include $(DEP)

.PHONY: all clean