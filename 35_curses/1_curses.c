#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>
int main()
{
	initscr();
	move(5,15);
	printw("%s","hello world!");
	refresh();
	sleep(2);
	printf("hello world!!\n");
	while(1);
	endwin();
	exit(EXIT_SUCCESS);
}
