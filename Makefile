FLAGS = -Wall -Wextra -lncurses -std=c99
USER_FLAGS = -lncurses
ZIG_FLAGS = -Wall -Wextra -lncurses -pedantic -fsanitize=undefined -Werror -std=c99

menu_object = src/menu.o
functions_object = src/functions.o
programs_object = src/programs.o
submenu_object = src/submenu.o

menu = src/menu.c -o $(menu_object)
functions = src/functions.c -o $(functions_object)
programs = src/programs.c -o $(programs_object)
submenu = src/submenu.c -o $(submenu_object)

full_recompilation:
	gcc $(FLAGS) -c $(menu)
	gcc $(FLAGS) -c $(functions)
	gcc $(FLAGS) -c $(programs)
	gcc $(FLAGS) -c $(submenu)
	@echo "Compiling full application"

user_recompilation:
	@gcc $(USER_FLAGS) -c $(menu)
	@gcc $(USER_FLAGS) -c $(function)
	@gcc $(USER_FLAGS) -c $(programs)
	@gcc $(USER_FLAGS) -c $(submenu)

zig_recompilation:
	zig cc $(ZIG_FLAGS) -c $(menu)
	zig cc $(ZIG_FLAGS) -c $(function)
	zig cc $(ZIG_FLAGS) -c $(programs)
	zig cc $(ZIG_FLAGS) -c $(submenu)

clean: 
	@rm src/menu.o
	@rm src/functions.o
	@rm src/programs.o
	@rm src/submenu.o

archc: user_recompilation
	@gcc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-center $(FLAGS)

arch-center: user_recompilation
	@gcc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-center $(FLAGS)


full: full_recompilation
	@gcc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-center $(FLAGS)

zigg: zig_recompilation
	@zig cc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-center $(ZIG_FLAGS)

