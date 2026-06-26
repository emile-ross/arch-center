#define _POSIX_C_SOURCE 200809L
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "enums.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

extern const int indent_left;
extern const int opt_indent_left;

extern int lines_from_top;
extern int amount_of_options;
extern int indent;
extern char cmd;

extern int delay_quarters; // max is 4 
extern int delay_seconds;
extern struct timespec install_timer;

int disk_management(void);
int settings_menu(void);
int system_monitoring(void);

void init_menu(void);
void delay(int delay_quarters, int delay_seconds);
void take_imput_menu(void);
void menu_tip(char *menu_type, int line);
void reset_imput(void);
