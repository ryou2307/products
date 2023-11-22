#include <ncurses.h>
#include <stdio.h>
#include "redraw.h"
#include <stdlib.h>
#include <time.h>

void redraw()
{

    srand((unsigned int)time(NULL));

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    timeout(100);

    POSITION *monster = malloc(sizeof(POSITION));

    monster->x = COLS / 2;
    monster->y = LINES / 2;

    char ch;
    while (ch != 'q')
    {
        mvprintw(monster->y, monster->x, " ");
        getMonsterLocation(monster);
        mvprintw(monster->y, monster->x, "M");
        ch = getch();
        refresh();
    }
    endwin();
}

void getMonsterLocation(POSITION *monster)
{

    int dx;
    dx = rand() % 3 - 1;
    int dy;
    dy = rand() % 3 - 1;

    if (monster->x > 0 && dx < 0)
    {
        monster->x = monster->x + dx;
    }
    else if (monster->x < COLS - 1 && dx > 0)
    {
        monster->x = monster->x + dx;
    }

    if (monster->y > 0 && dy < 0)
    {
        monster->y = monster->y + dy;
    }
    else if (monster->y < LINES - 1 && dy > 0)
    {
        monster->y = monster->y + dy;
    }
}
