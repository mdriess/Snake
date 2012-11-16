#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    /*
    Snake snake;
    Plotter p;
    
    snake.draw(p);
    Sleep(1000);
    */
    
    /*
    while(!snake.hit(0,100,0,100))
    {
        snake.setDirection(EAST);
        for(int i=0;i<10;i++)
        {   
            p.clear();
            snake.grow();
            snake.move();
            snake.draw(p);
            
            Sleep(100);
        }
        snake.setDirection(SOUTH);
        for(int i=0;i<10;i++)
        {
            p.clear();
            //cout << snake.getLocation().getY() << endl;
            //p.plot(15,15,65+snake.getLocation().getY());
            snake.move();
            snake.draw(p);
            
            Sleep(100);
        }
        snake.setDirection(WEST);
        for(int i=0;i<10;i++)
        {
            p.clear();
            snake.move();
            snake.draw(p);
            
            Sleep(100);
        }
        snake.setDirection(NORTH);
        for(int i=0;i<10;i++)
        {
            p.clear();
            snake.move();
            snake.draw(p);
            
            Sleep(100);
        }
    }
    */
    
    /*
    srand(time(0));
    for(int i=0;i<15;i++)
        snake.move();
    snake.setDirection(SOUTH);
    for(int i=0;i<15;i++)
        snake.move();
    int moves = 0;
    while(!snake.hit(0,100,0,100))
    {
        p.clear();
        snake.move();
        snake.draw(p);
        
        if(++moves % 10 == 0)
            snake.grow();
        
        snake.setDirection(Direction(rand()%4));
        Sleep(100);
    }
    */
    
    Game g;
    g.playGame();
    Sleep(1000);    
    
    return 0;
}
