#ifndef _POINT_HEADER
#define _POINT_HEADER

class Point
{
    private:
       int x;
       int y;

    public:
       //*********************************************************************************
       //description: creates a new Point at the coordinates specified by the ints       *
       //returns: none                                                                   *
       //pre: none                                                                       *
       //post: a Point is created with x at the first int and y at the second            *
       //*********************************************************************************
       Point(int, int);

       //*********************************************************************************
       //description: creates a default Point at (0,0)                                   *
       //returns: none                                                                   *
       //pre: none                                                                       *
       //post: a new Point is created with x and y = 0                                   *
       //*********************************************************************************
       Point();

       //*********************************************************************************
       //description: gets X                                                             *
       //returns: int                                                                    *
       //pre: X exists and is a int                                                      *
       //post: X remains unchanged                                                       *
       //*********************************************************************************
       int getX();

       //*********************************************************************************
       //description: gets Y                                                             *
       //returns: int                                                                    *
       //pre: Y exists and is a int                                                      *
       //post: Y remains unchanged                                                       *
       //*********************************************************************************
       int getY();

        //*********************************************************************************
        //description: sets X to the value of the int                                     *
        //returns: void                                                                   *
        //pre: X exists and is a int                                                      *
        //post: the value of the int is stored in X                                       *
        //*********************************************************************************
       void setX(int);

       //*********************************************************************************
       //description: sets Y to the value of the int                                     *
       //returns: void                                                                   *
       //pre: Y exists and is a int                                                      *
       //post: the value of the int is stored in Y                                       *
       //*********************************************************************************
       void setY(int);

       //*********************************************************************************
       //description: tests if two points are identical                                  *
       //returns: bool                                                                   *
       //pre: both points exist                                                          *
       //post: true if the points match, false if they do not                           *
       //*********************************************************************************
       bool equals(Point p);
};

#endif
