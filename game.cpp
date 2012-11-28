#include "game.h"

Game::Game()
{
    generateFood();

    user= User();
    dead   = false;
    paused = false;

    score = 1;
    speed = 0;
}

Game::Game(User& u)
{
    generateFood();

    user = u;

    dead   = false;
    paused = false;

    score = 1;
    speed = 0;
}

void Game::playGame()
{
    resizeConsole(x_max+1,y_max+1);//game size
    screen.clear();
    drawBoundary();

    while(!dead)
    {
        displayScore();

        if(!paused)
        {
            snake.clear(screen);
            snake.move();
            snake.draw(screen);

            food.draw(screen);

            Sleep(100-speed);


            if(snake.hit(x_min,x_max,y_min,y_max))
            {
                dead = true;
            }
            else if(snake.getHead().equals(food))
            {
                snake.grow();
                generateFood();
                harder();
            }
        }

        if(kbhit())
        {
            getKeys();
        }

    }
    //endgame();
    updateUser();
}

void Game::drawBoundary()
{
     drawLine(x_min , y_min , x_max-x_min+1 , false);
     drawLine(x_min , y_max , x_max-x_min+1 , false);
     drawLine(x_min , y_min , y_max-y_min+1 , true);
     drawLine(x_max , y_min , y_max-y_min+1 , true);
}

void Game::drawLine(int x, int y, int length, bool vert)
{
    if(vert)
    {
        for(int i = 0 ; i < length ; i++)
        {
            screen.plot(x,y+i,SQUARE);
        }
    }
    else
    {
        for(int i = 0; i < length ; i++)
        {
            screen.plot(x+i,y,SQUARE);
        }
    }
}

void Game::generateFood()
{
    srand(time(0));

    int dx = x_max - x_min - 2;
    int dy = y_max - y_min - 2;

    int x = rand() % dx + x_min + 1;
    int y = rand() % dy + y_min + 1;

    food = Node(Point(x,y));
}

bool Game::eatFood()
{
    return snake.hitNode(food);
}

void Game::displayScore()
{
    screen.move(65,0);
    cout << "Score: " << score;
}

void Game::getKeys()
{
    char c = getch();

    switch(c)
    {
        case 112: paused = true;
                  break;
        case 115: paused = false;
                  break;
    }

    if(c == -32) switch(getch())
    {
        case 72: if(snake.getDirection() % 2 != 0)
                     snake.setDirection(NORTH);
                 break;
        case 75: if(snake.getDirection() % 2 != 1)
                     snake.setDirection(WEST);
                 break;
        case 77: if(snake.getDirection() % 2 != 1)
                     snake.setDirection(EAST);
                 break;
        case 80: if(snake.getDirection() % 2 != 0)
                     snake.setDirection(SOUTH);
                 break;
    }

}

void Game::harder()
{
    score++;
    if(score % 5 == 0 && speed < 100)
    {
        speed += 10;
    }
}

void Game::updateUser()
{
    user.setScore(score);
    resizeConsole();
    usermenu(screen,user);
}

