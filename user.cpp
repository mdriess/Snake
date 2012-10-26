#include <iostream>
#include "user.h"
#include "menu.h"
#include <cstring>
#include "plotter.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void printLogin(){

    string username;
    string pw;

    Plotter screen;

    screen.clear();

    cout << "=== Login ===" << endl;

    cout << endl;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> pw;

    cout << login(username, pw);

    return;

}

int login(string username, string pw){

    int status;
    string filename;
    string actualPass;

    // attempt to open user file
    filename = "users\\" + username + ".usr";

    ifstream userFile;

    userFile.open(filename.c_str());

    if(!userFile){

        status = 0; // user doesn't exist

    } else {

        userFile >> actualPass;

        if(actualPass == pw){

            status = 1; // login successful

        } else {

            status = 2; // password mismatch

        }

    }

    userFile.clear();
    userFile.close();

    return status;

}
