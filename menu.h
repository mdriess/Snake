#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "plotter.h"
#include "user.h"
#define BACK 8
#define ENTER 13
#define ESC 27
#define UP 72
#define DOWN 80

void loadscreen();
void mainmenu(Plotter&);
void usermenu(Plotter& ,User& );
int menu(Plotter&screen, string title, string ary[],int size);
void userLogin(Plotter&);
int login(string, string);
string hintLookup(string);
int highScore(string);
void changePassword(Plotter&, User&);
void userSettings(Plotter&,User&);
void highScoreList(Plotter&);
void createAccount(Plotter&);
string enterPassword(Plotter&,int&,int&);
void resizeConsole(int = 25,int = 25);


#endif // MENU_H_INCLUDED
