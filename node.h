#ifndef _NODE_HEADER
#define _NODE_HEADER

#include "point.h"
#include "plotter.h"

class Node
{
    private:
       Point location;
       char symbol;

    public:

       //***********************************************************************************
       //description: creates a new Node at the specified point symbol = square            *
       //returns: nothing                                                                  *
       //pre: none                                                                         *
       //post: a new Node is created                                                       *
       //***********************************************************************************
       Node(Point);

       //*********************************************************************************
       //description: Constructs a default Node with a default Point and symbol = square *
       //returns: none                                                                   *
       //pre: none                                                                       *
       //post: a new Node is constructed with the above default characteristics          *
       //*********************************************************************************
       Node();

       //*********************************************************************************
       //description: gets Location                                                      *
       //returns: Point                                                                  *
       //pre: Location exists and is a Point                                             *
       //post: Location remains unchanged                                                *
       //*********************************************************************************
       Point getLocation();

        //*********************************************************************************
        //description: gets Symbol                                                        *
        //returns: char                                                                   *
        //pre: Symbol exists and is a char                                                *
        //post: Symbol remains unchanged                                                  *
        //*********************************************************************************
       char getSymbol();

        //*********************************************************************************
        //description: sets Location to the value of the Point                            *
        //returns: void                                                                   *
        //pre: Location exists and is a Point                                             *
        //post: the value of the Point is stored in Location                              *
        //*********************************************************************************
       void setLocation(Point);

       //*********************************************************************************
       //description: sets Symbol to the value of the char                               *
       //returns: void                                                                   *
       //pre: Symbol exists and is a char                                                *
       //post: the value of the char is stored in Symbol                                 *
       //*********************************************************************************
       void setSymbol(char);

       //*********************************************************************************
       //description: tests if two Nodes are identical                                   *
       //returns: bool                                                                   *
       //pre: both Nodes exist                                                           *
       //post: returns true if the Nodes are identical, false if they aren't             *
       //*********************************************************************************
       bool equals(Node);

       //*********************************************************************************
       //description: prints symbol at the locatioin stored in Point                     *
       //returns: void                                                                   *
       //pre: a Plotter is declared                                                      *
       //post: the character in symbol is printed at the Point in the Node               *
       //*********************************************************************************
       void draw(Plotter);

};

#endif
