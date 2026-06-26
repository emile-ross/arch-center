CC := gcc

FLAGS = -Wall -Wextra -lncurses -std=c99
USER_FLAGS = -lncurses
ZIG_FLAGS = -Wall -Wextra -lncurses -Wpedantic -fsanitize=undefined -Werror -std=c99 -Wconversion
SRCDIR := src/
SRCS = programs functions menu submenu
OUTPUT = -o arch-centre

SRC_FILES := $(addprefix $(SRCDIR), $(SRCS))

SRC_F_PATH := $(addsuffix .c, $(SRC_FILES))

archc:
	$(CC) $(SRC_F_PATH) $(OUTPUT) $(FLAGS)

base: 
	zig cc $(SRC_F_PATH) $(OUTPUT) $(ZIG_FLAGS)
