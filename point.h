#ifndef _POINT_HEADER
#define _POINT_HEADER

class Point
{
    private:
        int  x_pos;
        int  y_pos;
    
    public:
        Point(int = 0, int = 0);
        Point(Point*);

        void setX(int);
        void setY(int);

        int  getX();
        int  getY();
        
        bool equals(Point *p);
};

#endif
