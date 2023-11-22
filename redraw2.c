#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "redraw2.h"

void redraw2()
{

    POSITION *player = malloc(sizeof(POSITION));
    POSITION *monster = malloc(sizeof(POSITION));

    int count = 0, stage = 0, score = 0;
    int key;

    srand((unsigned int)time(NULL));

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    timeout(500);

    keypad(stdscr, true);

    initPlayerLocation(player);
    initMonsterLocation(monster);

    while (key != 'q')
    {
        count++;

        pointDisp(stage, score, count);

        mvprintw(monster->y, monster->x, " ");
        getMonsterLocation(monster);
        mvprintw(monster->y, monster->x, "M");

        mvprintw(player->y, player->x, " ");
        getPlayerLocation(player, key);
        mvprintw(player->y, player->x, "@");

        refresh();
        if (count == MAX_COUNT)
        {
            key = gameOver();
        }
        else if (encounter(player, monster) == 1)
        {
            sleep(2);
            stage++;
            score = MAX_COUNT - count;
            count = 0;

            initPlayerLocation(player);
            initMonsterLocation(monster);
        }
        else
        {
            key = getch();
        }
    }

    endwin();
}
