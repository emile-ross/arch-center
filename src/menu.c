#include "header.h"


int main(void) 
{
	const char *choices[] = 
	{
		"View system performance",
		"System monitoring",
		"Settings",
		"Exit",
	};
	
	const int n_choices = ARRAY_SIZE(choices);
	
	/* initialize ncurses */
	init_menu();
	
	int choice = -1;
	int highlight = 0;
	while (1) 
	{
		clear();
		mvprintw(0, 2, "Main menu");
		menu_tip("main", 2);
		
		for (int i = 0; i < n_choices; i++) 
		{
			if (i == highlight)
			{
				attron(A_REVERSE);
				mvprintw(3 + i, base_indent_left + indent_left, "%s", choices[i]);
				attroff(A_REVERSE);
			}
			else 
			{
				mvprintw(3 + i, base_indent_left, "%s", choices[i]);
			}
		}
		
		get_input(&choice, &highlight, &n_choices);
		
		if (choice == 3)
		{
			endwin();
			return 0;
		}
		else if (choice == 0)
		{
			choice = -1;
			highlight = 0;
		}
		else if (choice == 1)
		{
			system_monitoring();
			choice = -1;
			highlight = 0;
		}
		else if (choice == 2)
		{
			settings_menu();
			choice = -1;
			highlight = 0;
		}
		else
		{
			choice = -1;
		}
	}
	endwin();
	return 0;
}

