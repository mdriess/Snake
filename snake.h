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
       //*********************************************************************************
       //description: Constructs a Snake with body[0]                                    *
       //returns:                                                                        *
       //pre:                                                                            *
       //post:                                                                           *
       //*********************************************************************************
       Snake();

       //*********************************************************************************
       //description:                                                                    *
       //returns:                                                                        *
       //pre:                                                                            *
       //post:                                                                           *
       //*********************************************************************************
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

        //*********************************************************************************
        //description: gets Length                                                        *
        //returns: int                                                                    *
        //pre: Length exists and is a int                                                 *
        //post: Length remains unchanged                                                  *
        //*********************************************************************************
       int   getLength();

       //*********************************************************************************
       //description: gets Location                                                      *
       //returns: Point                                                                  *
       //pre: Location exists and is a Point                                             *
       //post: Location remains unchanged                                                *
       //*********************************************************************************
       Point getLocation();

        //*********************************************************************************
        //description: gets Head                                                          *
        //returns: Node                                                                   *
        //pre: Head exists and is a Node                                                  *
        //post: Head remains unchanged                                                    *
        //*********************************************************************************
        Node  getHead();

        //*********************************************************************************
        //description: sets Direction to the value of the Direction                       *
        //returns: void                                                                   *
        //pre: Direction exists and is a Direction                                        *
        //post: the value of the Direction is stored in Direction                         *
        //*********************************************************************************
        void  setDirection(Direction);

       //*********************************************************************************
       //description: gets Direction                                                     *
       //returns: Direction                                                              *
       //pre: Direction exists and is a Direction                                        *
       //post: Direction remains unchanged                                               *
       //*********************************************************************************
       Direction getDirection();
};

#endif
