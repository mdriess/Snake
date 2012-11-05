#include "snake.h"

using namespace std;

Snake::Snake()
{
    head = new Node();
    tail = head;
    
    length = 1;
    dir = EAST;
}

Snake::Snake(Node* t)
{
    head = new Node(t);
    tail = head;
    
    length = 1;
    dir = EAST;
}  

void Snake::move()
{
     moveBody();
     moveHead();
}

void Snake::moveBody()
{
    Node* tmp = tail;
       
    while(tmp->getNext() != NULL)
    {
        tmp->setPoint(tmp->getNext()->getPoint());
        tmp->setSym(tmp->getNext()->getSym());
        
        tmp = tmp->getNext();
    }
}

void Snake::moveHead()
{
    Point *p = head->getPoint();
    switch(dir)
    {
        case NORTH:
             p->setY(p->getY()-1);
             break;
        case SOUTH:
             p->setY(p->getY()+1);
             break;
        case EAST:
             p->setX(p->getX()+1);
             break;
        case WEST:
             p->setX(p->getX()-1);
             break;
    }
    head->setPoint(p);
}

bool Snake::draw(Plotter plotter)
{
    bool ret;
    
    ret = drawBody(plotter);
    drawHead(plotter);
    
    return ret;
}

bool Snake::drawBody(Plotter plotter)
{
    bool ret  = true;
    Node *tmp = tail;
    
    while(tmp->getNext() != NULL)
    {
        plotter.plot(tmp->getPoint()->getX(),tmp->getPoint()->getY(),tmp->getSym());
        
        if(tmp->equals(head))
        {
            ret = false;
        }
        
        tmp = tmp->getNext();
    }
    
    return ret;
}

void Snake::drawHead(Plotter plotter)
{
    Point *p = head->getPoint();
    plotter.plot(p->getX(),p->getY(),head->getSym());
}
              
void Snake::grow()
{
    if(length == 1)
    {
        tail = new Node(head);
        tail->setNext(head);
    }
    else
    {
        Node *tmp;
        tmp = new Node(tail);
        tmp->setNext(tail);
        tail = tmp;
    }
    
    length++;
}

void Snake::add(Node *n)
{
    if(length == 1)
    {
        n->setNext(head);
    }
    else
    {
        n->setNext(tail);
    }
    tail = n;
    
    length++;
}

int Snake::getLength()
{
    return length;
}

Node* Snake::getTail()
{
    return tail;
}

Node* Snake::getHead()
{
    return head;
}
               
void Snake::setDir(direction d)
{
    dir = d;
}
