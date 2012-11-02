#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "plotter.h"
#include "user.h"

/*  loading screen

    Description: Prints loading screen until keypress

*/
void loadscreen();

/*  main menu

    Description: Prints menu options and listens for which
        functions to call

*/
void mainmenu(Plotter&);

/*  user menu

    Description: Prints user menu options and listens for which
        functions to call

*/
void usermenu(User& username);

#endif // MENU_H_INCLUDED
