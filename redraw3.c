#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "redraw.h"
#include "redraw2.h"
#include "player.h"
#include "zombie.h"

void redraw3()
{
    POSITION *player = malloc(sizeof(POSITION));
    POSITION *monster = malloc(sizeof(POSITION));
    POSITION zombie[50];
    for (int i = 0; i < MAX_ZOMBIE; i++)
    {
        zombie[i];
    }

    int count = 0, stage = 1, score = 0, highScore = 0;
    int key = 0;

    srand((unsigned int)time(NULL));

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    timeout(500);

    keypad(stdscr, true);

    initPlayerLocation(player);
    initMonsterLocation(monster);

    highScore = loadHighScore();

    while (key != 'q')
    {
        count++;

        highScore=  getHighScore(highScore,score);
        highScoreDisp(highScore);
        pointDisp(stage - 1, score, MAX_COUNT - count);

        mvprintw(monster->y, monster->x, " ");
        getMonsterLocation(monster);
        mvprintw(monster->y, monster->x, "M");

        for (int i = 0; i < stage - 1; i++)
        {
            mvprintw(zombie[i].y, zombie[i].x, " ");
            getZombieLocation(zombie,i,player);
            mvprintw(zombie[i].y, zombie[i].x, "Z");
        }

        mvprintw(player->y, player->x, " ");
        getPlayerLocation(player, key);
        mvprintw(player->y, player->x, "@");

        refresh();

        if (count == MAX_COUNT)
        {
            key = gameOver();
            saveHighScore(highScore);
        }
        else if (caughtByZombie(player, zombie, stage - 1))
        {
            key = gameOver();
            saveHighScore(highScore);
        }
        else if (encounter(player, monster))
        {
            sleep(2);
            stage++;
            score += MAX_COUNT - count;
            count = 0;

            initZombie(zombie, stage);

            initPlayerLocation(player);
            initMonsterLocation(monster);
        }
        else
        {
            key = getch();
        }
    }

    endwin();
    free(player);
    free(monster);
}
