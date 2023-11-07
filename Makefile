CC = gcc
CPPFLAGS = -MMD
CDEVFLAGS = -Wall -Wextra -Wshadow -pedantic-errors -g -std=c99
CRELFLAGS = -pedantic -std=c99 -O3 -DNDEBUG
LDFLAGS = 
LDLIBS = 

BUILD = build

SRC = src/*.c
OBJ = $(BUILD)/$(SRC:.c=.o)
DEP = $(BUILD)/$(SRC:.c=.d)
EXE = $(BUILD)/bmenu

all: rel

rel: setup
	@$(CC) -o $(EXE) $(SRC) $(CRELFLAGS)

dev: setup
	@$(CC) -o $(EXE) $(SRC) $(CDEVFLAGS)

run:
	./$(EXE)

setup:
	@mkdir -p $(BUILD)

# -include ${DEP}

.PHONY: all rel dev run setup clean reset

clean:
	@$(RM) $(OBJ)
	@$(RM) $(DEP)

reset:
	@$(RM) -rf $(BUILD)

# END
