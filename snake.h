#ifndef _SNAKE_HEADER
#define _SNAKE_HEADER

#include <fstream>
#include "plotter.h"
#include "node.h"
using namespace std;

enum  Direction {NORTH, EAST, SOUTH, WEST};

const int CAPACITY = 1000;

class Snake
{
    
    private:
       Node  body[CAPACITY];
       Direction direction;
       int length;
    
    public:
       Snake();
       Snake(ifstream&);
       
       void grow();
       void move();
       void moveBody();
       void moveHead();
       void draw(Plotter);
       
       bool hit(int vert_low, int vert_up, int horz_low, int horz_up);
       bool hitItself();
       bool hitWall(int vert_low, int vert_up, int horz_low, int horz_up);
       
       Point getLocation();
       void  setDirection(Direction);
};

#endif
