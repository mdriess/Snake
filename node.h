#ifndef _NODE_HEADER
#define _NODE_HEADER

#include "point.h"

class Node
{     
    private:
       Point location;
       char symbol;
       
    public:
       Node(Point);
       Node();
       
       Point getLocation();
       char getSymbol();
       
       void setLocation(Point);
       void setSymbol(char);
       
       bool equals(Node);
};

#endif
