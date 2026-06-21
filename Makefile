CC := gcc

FLAGS = -Wall -Wextra -lncurses -std=c99
USER_FLAGS = -lncurses
ZIG_FLAGS = -Wall -Wextra -lncurses -Wpedantic -fsanitize=undefined -Werror -std=c99 -Wconversion
SRCS := src/programs.c src/functions.c src/menu.c src/submenu.c
OUTPUT = -o $(submenu_object)

SRC_FILES := $(addprefix $(SRCDIR), $(SRCS)) $(OUTPUT)

archc: user_recompilation
	$(CC) $(SRC_FILES) $(FLAGS)

arch-centre: user_recompilation
	@gcc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-centre $(FLAGS)

base: 
	zig cc $(SRC_FILES) $(ZIG_FLAGS)

