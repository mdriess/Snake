#include "snake.h"

Snake::Snake()
{
    body[0] = Node();
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

void Snake::draw(Plotter p)
{
    Point location;
    
    for(int i = 0 ; i < length ; i++)
    {
        location = body[i].getLocation();
        p.plot(location.getX() , location.getY() , body[i].getSymbol());
    }
}

bool Snake::hit(int vert_low, int vert_up, int horz_low, int horz_up)
{
    return hitItself() || hitWall(vert_low , vert_up , horz_low , horz_up);
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

bool Snake::hitWall(int vert_low, int vert_up, int horz_low, int horz_up)
{
    bool  ret = false;
    Point location = body[0].getLocation();
    
    if(location.getY() < vert_low)
    {
        ret = true;
    }
    if(location.getY() > vert_up)
    {
        ret = true;
    }
    if(location.getX() < horz_low)
    {
        ret = true;
    }
    if(location.getX() > horz_up)
    {
        ret = true;
    }
    
    return ret;
}

Point Snake::getLocation()
{
    return body[0].getLocation();
}

void Snake::setDirection(Direction d)
{
    if(direction % 2 != d % 2)
    {
        direction = d;
    }
}
