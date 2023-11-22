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

int caughtByZombie(POSITION *player, POSITION *zombie, int zombieNum)
{
    for (int i = 0; i < zombieNum; i++)
    {
        if (player->x == zombie[i].x && player->y == zombie[i].y)
        {
            return 1;
        }
    }
    return 0;
}

void initZombie(POSITION *zombie, int stage)
{
        for (int i = 0; i < stage - 2; i++)
        {
            mvprintw(zombie[i].y, zombie[i].x, " ");
        }

        int center_x = COLS / 2;
        int center_y = LINES / 2;

        srand(time(NULL));
        for (int i = 0; i < stage - 1; i++)
        {
            zombie[i].x = center_x - 10 + rand() % 21;
            zombie[i].y = center_y - 10 + rand() % 21;

            mvprintw(zombie[i].y, zombie[i].x, "z");
        }
}

void getZombieLocation(POSITION *zombie, int i, POSITION *player)
{
    int t = rand() % 2;
    double bekutoru_x = ((player->x - zombie[i].x));
    double bekutoru_y = ((player->y - zombie[i].y) );

    double bekutoru_z = sqrt((bekutoru_x * bekutoru_x) + (bekutoru_y * bekutoru_y));

    double X = bekutoru_x / bekutoru_z * 2;
    double Y = bekutoru_y / bekutoru_z * 2;

    zombie[i].x += X*t;
    zombie[i].y += Y*t;
}

int getHighScore(int highScore, int score)
{
    if (score > highScore)
    {
        return score;
    }
    else
    {
        return highScore;
    }
}

int loadHighScore()
{
    FILE *file = fopen("highscore.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    int highScore;
    int result = fscanf(file, "%d", &highScore);

    fclose(file);

    if (result != 1)
    {
        printf("Error reading score.\n");
        return 0;
    }

    return highScore;
}

void saveHighScore(int score)
{
    FILE *file = fopen("highscore.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d", score);
    fclose(file);
}

void highScoreDisp(int highScore)
{
    initscr();
    clear();

    int midX = COLS / 2 + 2;
    mvprintw(0, midX, "HI SCORE : %d", highScore);
}
