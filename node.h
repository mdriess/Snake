#ifndef _NODE_HEADER
#define _NODE_HEADER
#include "plotter.h"
#include "point.h"

class Node
{
    private:
        Node* next;
        Point* point;
        char symbol;
    
    public:
        Node();
        Node(Point*, char = SQUARE);
        Node(Node* n);
        
        void setNext(Node*);
        void setPoint(Point*);
        void setSym(char);
        
        Node*  getNext();
        Point* getPoint();
        char   getSym();
        
        bool equals(Node*);
};

#endif
