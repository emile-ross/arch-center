#include "header.h"

void init_menu(void)
{
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
}

long int time_timer_quarters;
long int time_timer_seconds;

const int indent_left = 1;
int lines_from_top;
int amount_of_options;

void display_menu(int d_highlight, int d_amount_of_options, const char **d_options_text, int d_lines_from_top, int d_indent_left)
{
	for (int i = 0; i < d_amount_of_options; i++) 
	{
		if (i == d_highlight)
		{
			attron(A_REVERSE);
			mvprintw(d_lines_from_top + i, d_indent_left, "%s", d_options_text[i]);
			attroff(A_REVERSE);
		}
		else 
		{
			mvprintw(d_lines_from_top + i, d_indent_left, "%s", d_options_text[i]);
		}
	}
}

void delay(int delay_quarters, int delay_seconds)
{
	struct timespec install_timer; 
	if (delay_quarters < 4)
	{
		time_timer_quarters = delay_quarters * 250000000;
		time_timer_seconds = delay_seconds;
	}
	else if (delay_quarters == 4)
	{
		time_timer_quarters = 0;
		time_timer_seconds = delay_seconds + 1;
	}
	else
	{
		printw("Invalid use of delay function\n"); 
		printw("You're stupid\n"); 
	}
	
	install_timer.tv_nsec = time_timer_quarters;
	install_timer.tv_sec = time_timer_seconds;
	nanosleep(&install_timer, NULL);
}

void menu_tip(char *menu_type, int line)
{
	if (strcmp(menu_type, "main") == 0) // Main menus
	{
		mvprintw(indent_left, line, "Press \"q\" to quit");
	}
	else if (strcmp(menu_type, "sub") == 0) // Main menus
	{
		mvprintw(indent_left, line, "Press \"b\" to go back");
	}
	else
	{
		mvprintw(indent_left, line, "\"Invalid tip integer\"");
	}
}
