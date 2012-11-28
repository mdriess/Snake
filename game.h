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

       //**********************************************************************************
       //description: generates a random food Node on the game screen, user is the default*
       //             user, dead and paused are false, and score and speed = 0            *
       //returns: none                                                                    *
       //pre: none                                                                        *
       //post: a game is set up for an anonymous user                                     *
       //**********************************************************************************
       Game();

       //*********************************************************************************
       //description: creates a game, doing the same thing as the default constructor,   *
       //             except the user is the user passed to the constructor.             *
       //returns: none                                                                   *
       //pre: none                                                                       *
       //post:                                                                           *
       //*********************************************************************************
       Game(User&);
       //*********************************************************************************
       //description: runs all of the functions of the game (moving the Snake, eating    *
       //             food, dying, keeping score)                                        *
       //returns: void                                                                   *
       //pre: the console window is open                                                 *
       //post: a game of snake is begun and run.                                        *
       //*********************************************************************************
       void playGame();

       //*********************************************************************************
       //description: draws the border around the screen                                 *
       //returns: void                                                                   *
       //pre: playGame() has been called                                                 *
       //post: a border is drawn around the screen                                       *
       //*********************************************************************************
       void drawBoundary();

       //*********************************************************************************
       //description: draws a line on the screen, starting at the x&y coordinates and    *
       //             contiuing until"length" is reached
       //returns: void                                                                   *
       //pre: a plotter window is open                                                   *
       //post: a line is drawn on the screen                                             *
       //*********************************************************************************
       void drawLine(int x, int y, int length, bool vert);

       //*********************************************************************************
       //description:generates a random food point somewhere on the screen, except for on*
       //            the borders
       //returns: void                                                                   *
       //pre: playgame() has been called                                                 *
       //post: a food point is placed randomly on the screen                             *
       //*********************************************************************************
       void generateFood();

       //*********************************************************************************
       //description: detects whether the snake has collided with the food               *
       //returns: bool                                                                   *
       //pre: playgame() is called                                                       *
       //post: true if the snake hit food, false if hit hasn't                           *
       //*********************************************************************************
       bool eatFood();

       //*********************************************************************************
       //description: gets the keys pressed by the user and acts accordingly (changing   *
       //             direction, pausing, resuming, quitting)                            *
       //returns: void                                                                   *
       //pre: playgame() has been called                                                 *
       //post: the game reacts accordingly to any keys the user presses                  *
       //*********************************************************************************
       void getKeys();

       //*********************************************************************************
       //description:  increases score and difficulty when appropriate                   *
       //returns: void                                                                   *
       //pre: playgame() has been called                                                 *
       //post: score is updated and snake moves faster every 5 points                    *
       //*********************************************************************************
       void harder();
       //*********************************************************************************
       //description: shows the score of the game                                        *
       //returns: void                                                                   *
       //pre: playgame() has been called                                                 *
       //post:                                                                           *
       //*********************************************************************************
       void displayScore();

       //*********************************************************************************
       //description: saves the user's high score and sends the game back to the menu    *
       //returns: void                                                                   *
       //pre: the snake is dead                                                          *
       //post: a new high score is saved in the user and the game goes back to the menu  *
       //*********************************************************************************
       void updateUser();

       //*********************************************************************************
       //description: displays game over message and updates User object                 *
       //returns: nothing                                                                *
       //pre: Snake is dead                                                              *
       //post: updates user, resizes screen and returns to user menu                     *
       //*********************************************************************************
       void endgame();
};

#endif
