#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/*  loading screen

    Description: Prints loading screen until keypress

*/
void loadscreen();

/*  main menu

    Description: Prints menu options and listens for which
        functions to call

*/
void mainmenu();

/*  user menu

    Description: Prints user menu options and listens for which
        functions to call

*/
void usermenu(std::string username);

#endif // MENU_H_INCLUDED
