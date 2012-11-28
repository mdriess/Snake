#ifndef _GAME_H
#define _GAME_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "snake.h"
#include "user.h"
#include "menu.h"

using namespace std;

const int x_min = 0, x_max = 78, y_min = 1, y_max = 24;

class Game
{
    private:
       Plotter screen;

       Snake snake;
       User  user;
       Node  food;
       bool  dead;

       bool paused;
       int  score;
       int  speed;

    public:
       Game();
       Game(User&);

       void playGame();

       void drawBoundary();
       void drawLine(int x, int y, int length, bool vert);

       void generateFood();
       bool eatFood();

       void getKeys();
       void harder();
       void displayScore();
       void updateUser();
};

#endif
