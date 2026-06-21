CC := gcc

FLAGS = -Wall -Wextra -lncurses -std=c99
USER_FLAGS = -lncurses
ZIG_FLAGS = -Wall -Wextra -lncurses -Wpedantic -fsanitize=undefined -Werror -std=c99 -Wconversion
OUTPUT = -o $(submenu_object)
SRCDIR := src/

SRC_FILES := $(addprefix $(SRCDIR), $(SRCS)) $(OUTPUT)
OBJ_EXT = .o

archc: user_recompilation
	$(CC) $(SRC_FILES) $(FLAGS)
SRC_FILES := $(addprefix $(SRCDIR), $(SRCS))

arch-centre: user_recompilation
	@gcc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-centre $(FLAGS)
OBJ_F_PATH := $(addsuffix $(OBJ_EXT), $(SRC_FILES))

base: 
	zig cc $(SRC_FILES) $(ZIG_FLAGS)

clean:
	rm $(OBJ_F_PATH)
