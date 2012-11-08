#include "point.h"

Point::Point(int a, int b)
{
    x = a;
    y = b;
}

Point::Point()
{
    x = 0;
    y = 0;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

void Point::setX(int n)
{
    x = n;
}

void Point::setY(int n)
{
    y = n;
}

bool Point::equals(Point p)
{
    return x == p.getX() && y == p.getY();
}
