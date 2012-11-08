#include "node.h"
#include "plotter.h"

Node::Node(Point p)
{
    location = p;
    symbol = SQUARE;
}

Node::Node()
{
    location = Point();
    symbol = SQUARE;
}

Point Node::getLocation()
{
    return location;
}

char Node::getSymbol()
{
     return symbol;
}

void Node::setLocation(Point p)
{
     location = p;
}

void Node::setSymbol(char c)
{
     symbol = c;
}

bool Node::equals(Node n)
{
     return location.equals(n.getLocation());
}
