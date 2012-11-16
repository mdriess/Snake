#ifndef _SNAKE_HEADER
#define _SNAKE_HEADER

#include <fstream>
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
       
       void clear(Plotter);
       void draw(Plotter);
       
       bool hit(int x_min, int x_max, int y_min, int y_max);
       bool hitItself();
       bool hitWall(int x_min, int x_max, int y_min, int y_max);
       bool hitNode(Node);
       
       int   getLength();
       Point getLocation();
       Node  getHead();
       
       void  setDirection(Direction);
       Direction getDirection();
};

#endif
