#include "snake.h"

Snake::Snake()
{
    body[0] = Node(Point(1,2));
    length = 1;
    direction = EAST;
}

Snake::Snake(ifstream& file)
{
    int x, y, dir;
    
    file >> length;
    if(length > CAPACITY)
    {
        length = CAPACITY;
    }
    
    file >> dir;
    direction = Direction(dir);
    
    for(int i = 0 ; i < length ; i++)
    {
        file >> x >> y;
        body[i] = Node(Point(x,y));
    }
}

void Snake::grow()
{
    if(length < CAPACITY)
    {
        length++;
    }
}

void Snake::move()
{
    moveBody();
    moveHead();
}

void Snake::moveBody()
{
    for(int i = length-1 ; i > 0 ; i--)
    {
        body[i] = body[i-1];
    }
}

void Snake::moveHead()
{
    Point location = body[0].getLocation();
    int x = location.getX(), y = location.getY();
    
    switch(direction)
    {
        case NORTH: location.setY(y-1); 
                    break;
                    
        case SOUTH: location.setY(y+1);
                    break;
        
        case EAST:  location.setX(x+1);
                    break;
        
        case WEST:  location.setX(x-1);
                    break;
    }
    
    body[0].setLocation(location);
}

void Snake::clear(Plotter p)
{
    Point tail_loc = body[length-1].getLocation();
    
    p.plot(tail_loc.getX(), tail_loc.getY(), ' ');
}

void Snake::draw(Plotter p)
{
    Point head_loc = body[0].getLocation();
    
    p.plot(head_loc.getX(), head_loc.getY(), SQUARE);
}

bool Snake::hit(int x_min, int x_max, int y_min, int y_max)
{
    return hitItself() || hitWall(x_min , x_max , y_min , y_max);
}

bool Snake::hitItself()
{
    bool ret = false; 
     
    Point location = body[0].getLocation();
    for(int i = 1 ; i < length ; i++)
    {
        if(body[i].getLocation().equals(location))
        {
            ret = true;
        }
    }
    
    return ret;
}

bool Snake::hitWall(int x_min, int x_max, int y_min, int y_max)
{
    bool  ret = false;
    Point location = body[0].getLocation();
    
    if(location.getX() <= x_min)
    {
        ret = true;
    }
    if(location.getX() >= x_max)
    {
        ret = true;
    }
    if(location.getY() <= y_min)
    {
        ret = true;
    }
    if(location.getY() >= y_max)
    {
        ret = true;
    }
    
    return ret;
}

bool Snake::hitNode(Node n)
{
    bool ret = false; 
     
    for(int i = 0 ; i < length ; i++)
    {
        if(body[i].equals(n))
        {
            ret = true;
        }
    }
    
    return ret;
}

int Snake::getLength()
{
    return length;
}

Point Snake::getLocation()
{
    return body[0].getLocation();
}

Node Snake::getHead()
{
    return body[0];
}

void Snake::setDirection(Direction d)
{
    if(direction % 2 != d % 2)
    {
        direction = d;
    }
}

Direction Snake::getDirection()
{
    return direction;
}
