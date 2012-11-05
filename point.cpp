#include <iostream>
#include "point.h"

using namespace std;

Point::Point(int x, int y)
{
    x_pos  = x;
    y_pos  = y;
}

Point::Point(Point *p)
{
    x_pos = p->getX();
    y_pos = p->getY();
}

void Point::setX(int x)
{
    x_pos = x;
}

void Point::setY(int y)
{
    y_pos = y;
}

int Point::getX()
{
    return x_pos;
}

int Point::getY()
{
    return y_pos;
}

bool Point::equals(Point *p)
{
    return x_pos == p->getX() && y_pos == p->getY();
}
