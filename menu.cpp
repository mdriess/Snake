#include <iostream>
#include "menu.h"
#include "plotter.h"
#include "user.h"
#include <cstring>

using namespace std;

void loadscreen(){

    Plotter screen;

    screen.clear();

    do{
        cout << "Beautiful Loading Screen" << endl;

        // we will want to beautify this page using
        // ascii art + plotter.cpp eventually

        cout << "                 __" << endl;
        cout << "     _______    /*_>-<" << endl;
        cout << " ___/ _____ \\__/ /" << endl;
        cout << "<____/     \\____/" << endl;

        cout << "Press any key to continue.." << endl;

    }while (!getch());

    mainmenu();

    // clear screen using plotter

    return;

}

void mainmenu(){

    int ans;

    Plotter screen;

    screen.clear();

    cout << "=== MAIN MENU ===" << endl;
    cout << "1. Login" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Forgot Password?" << endl;
    cout << "4. High Scores" << endl;
    cout << "5. Settings" << endl;
    cout << "6. Anonymous Play" << endl;
    cout << "9. Quit" << endl;

    cout << endl;
    cout << endl;

    cout << "Please enter the number of your selection: ";

    ans = getch();
    cout << static_cast<char>(ans) << endl;

    while(ans != '1' && ans != '2' && ans != '3' && ans != '4' && ans != '5'
          && ans != '6' && ans != '9'
          ){

        cout << "ERROR: Invalid selection. Please try again." << endl;

        ans = getch();
        cout << static_cast<char>(ans) << endl;

    }

    switch(ans){

        case '1': printLogin(1);
        break;
        case '2': cout << "Load create account";
        break;
        case '3': printLogin(0);
        break;
        case '4': cout << "High scores";
        break;
        case '5': cout << "Settings";
        break;
        case '6': cout << "Anonymous play";
        break;
        case '9': loadscreen();

    }

    return;

}

void usermenu(std::string username){

    Plotter screen;

    screen.clear();

    int ans;

    cout << "Welcome, " << username << "!  ";
    cout << "Your high score: " << highScore(username) << endl;
    cout << endl;

    cout << "=== USER MENU ===" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. High Scores" << endl;
    cout << "3. My Account" << endl;
    cout << "4. Settings" << endl;
    cout << "9. Log out" << endl;

    cout << endl;
    cout << endl;

    cout << "Please enter the number of your selection: ";

    ans = getch();
    cout << static_cast<char>(ans) << endl;

    while(ans != '1' && ans != '2' && ans != '3' && ans != '4' && ans != '9'){

        cout << "ERROR: Invalid selection. Please try again." << endl;

        ans = getch();
        cout << static_cast<char>(ans) << endl;

    }

    switch(ans){

        case '1': cout << "Load game!";
        break;
        case '2': cout << "Load high scores";
        break;
        case '3': cout << "Load my account";
        break;
        case '4': cout << "Load settings";
        break;
        case '9': mainmenu();

    }

    return;

}
