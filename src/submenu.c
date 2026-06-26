#include "header.h"


int system_monitoring(void)
{
	int choice = -1;
	int highlight = 0;
	const size_t cmd_size = 16;

	while(1)
	{
		const char *choices[] = 
		{
			"htop",
			"btop",
			"glances",
			"Back",
		};
	
		clear();
	
		mvprintw(0, 2, "View system activity using one of the following programs");
		menu_tip("sub", 2);
	
		int n_choices = ARRAY_SIZE(choices);
		for (int i = 0; i < n_choices; i++) 
		{
			if (i == highlight)
			{
				attron(A_REVERSE);
				mvprintw(3 + i, opt_indent_left + 1, "%s", choices[i]);
				attroff(A_REVERSE);
			}
			else 
			{
				mvprintw(3 + i, opt_indent_left, "%s", choices[i]);
			}
		}
	
		int c = getch();
		switch (c) 
		{
		case KEY_UP:
			highlight--;
			if (highlight < 0)
			{
				highlight = n_choices - 1;
			}
			break;

		case KEY_DOWN:
			highlight++;
			if (highlight >= n_choices)
			{
				highlight = 0;
			}
			break;

		case 10:  /* Enter key */
			  choice = highlight;
			  break;

		case 'b':
			  endwin();
			  return 0;
		}
	
		char *cmd = malloc(cmd_size);
		switch (choice)
		{
		case 0:
			snprintf(cmd, cmd_size,
					"htop");
			system(cmd);
			
			choice = -1;
			highlight = 0;
			
			break;
		case 1:
			snprintf(cmd, cmd_size,
					"btop");
			system(cmd);
		
			choice = -1;
			highlight = 0;
		
			break;
		case 2:
			snprintf(cmd, cmd_size,
					"glances");
			system(cmd);
			
			choice = -1;
			highlight = 0;
		
			break;
		
		case 3:
			endwin();
			return 0;
		default:
			break;
		}

		free(cmd);
	}
	endwin();
	return 0;
}

int settings_menu(void)
{
	int highlight = 0;
	int choice = -1;
	
	while(1)
	{
		const char *choices[] = 
		{
			"Configure this program",
			"Packages",
			"Configure dotfiles",
			"Back",
		};
		clear();
	
		mvprintw(0, 2, "Settings");
		menu_tip("sub", 2);
	
		int n_choices = ARRAY_SIZE(choices);
		for (int i = 0; i < n_choices; i++) 
		{
			if (i == highlight)
			{
				attron(A_REVERSE);
				mvprintw(3 + i, opt_indent_left + 1, "%s", choices[i]);
				attroff(A_REVERSE);
			}
			else 
			{
				mvprintw(3 + i, opt_indent_left, "%s", choices[i]);
			}
		}

		int c = getch();
	
		switch (c) 
		{
		case KEY_UP:
			highlight--;
			if (highlight < 0)
				highlight = n_choices - 1;
			break;
	
		case KEY_DOWN:
			highlight++;
			if (highlight >= n_choices)
				highlight = 0;
			break;
	
		case 10:  /* Enter key */
			choice = highlight;
			break;
			
		case 'b':
			endwin();
			return 0;
		}
	
		size_t cmd_size = 32;
		char *cmd = malloc(cmd_size);
		switch (choice)
		{
		case 0:
			highlight = 0;
			choice = -1;
			
			break;
		case 1:
			snprintf(cmd, cmd_size,
					"sudo pacman -Q");
			system(cmd);
			
			getch(); /* intended blocking behaviour */
			
			highlight = 0;
			choice = -1;
			
			break;
		case 2:
			highlight = 0;
			choice = -1;
			
			break;
		case 3: /* back button */
			endwin();
			return 0;
		default:
			choice = -1;
			break;
		}
		free(cmd);
	}
	endwin();
	return 0;
}
	
	
int disk_management(void)
{
	int highlight = 0;
	int choice = -1;
	
	while(1)
	{
		const char *choices[] = 
		{
			"Manage disk space with Wiper",
			"Gnome Disk Utility",
			"WIP",
			"WIP",
		};

		clear();
	
		mvprintw(0, 2, "Disk management");
		menu_tip("sub", 2);
	
		int n_choices = ARRAY_SIZE(choices);
		for (int i = 0; i < n_choices; i++) 
		{
			if (i == highlight)
			{
				attron(A_REVERSE);
				mvprintw(3 + i, opt_indent_left + 1, "%s", choices[i]);
				attroff(A_REVERSE);
			}
			else 
			{
				mvprintw(3 + i, opt_indent_left, "%s", choices[i]);
			}
		}

		int c = getch();
	
		switch (c) 
		{
			case KEY_UP:
				highlight--;
				if (highlight < 0)
					highlight = n_choices - 1;
				break;
	
			case KEY_DOWN:
				highlight++;
				if (highlight >= n_choices)
					highlight = 0;
				break;
	
			case 10:  /* Enter key */
				choice = highlight;
			    	break;
	
			case 'b':
				endwin();
				return 0;
		}
	    
		switch (choice)
		{
		case 0:
			highlight = 0;
			choice = -1;
		
			break;
		case 1:
			highlight = 0;
			choice = -1;
		
			break;
		case 2:
			highlight = 0;
			choice = -1;
		
			break;
		case 3: /* back button */
			endwin();
		    	return 0;
		default:
			choice = -1;
			break;
		}
	}
	endwin();
	return 0;
}
