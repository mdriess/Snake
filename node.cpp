#include "node.h"

using namespace std;

Node::Node()
{
    point = new Point();
    symbol = SQUARE;
    next   = NULL;
}

Node::Node(Point *p, char sym)
{
    point  = p;
    symbol = sym;
    next   = NULL;
}

Node::Node(Node* n)
{
    point  = new Point(n->getPoint());
    symbol = n->getSym();
    next   = n;
}

void Node::setNext(Node* n)
{
    next = n;
}

void Node::setPoint(Point *p)
{
    point = new Point(p);
}

void Node::setSym(char sym)
{
    symbol = sym;
}

Node* Node::getNext()
{
    return next;
}

Point* Node::getPoint()
{
    return point;
}

char Node::getSym()
{
    return symbol;
}

bool Node::equals(Node *n)
{
    return point->equals(n->getPoint());
}
