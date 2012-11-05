#ifndef _SNAKE_HEADER
#define _SNAKE_HEADER
#include "plotter.h"
#include "node.h"

class Snake
{
    public:
        enum  direction {NORTH, SOUTH, EAST, WEST};
      
    private:
        Node  *tail, *head;
        int   length;
        direction dir;
      
    public:
        Snake();
        Snake(Node*);
    
        void move();
        void moveBody();
        void moveHead();
        bool draw(Plotter);
        bool drawBody(Plotter);
        void drawHead(Plotter);
       
        void grow();
        void add(Node* n);
       
        int   getLength();
        Node* getTail();
        Node* getHead();
       
        void setDir(direction d);
};

#endif
