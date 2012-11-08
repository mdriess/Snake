#ifndef _POINT_HEADER
#define _POINT_HEADER

class Point
{
    private:
       int x;
       int y;
    
    public:
       Point(int, int);
       Point();
       
       int getX();
       int getY();
       
       void setX(int);
       void setY(int);
       
       bool equals(Point p);
};

#endif
