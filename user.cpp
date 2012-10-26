#include <iostream>
#include "user.h"
#include "menu.h"
#include <cstring>
#include "plotter.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void printLogin(int type){

    string username;
    string pw;
    string pwhint;
    int status;
    int cx, cy;
    char c;

    cx = 0;
    cy = 0;

    Plotter screen;

    screen.clear();

    screen.move(cx,cy);

    do{

        if(type != 0){

            cout << "=== Login ===" << endl;

        } else {

            cout << "=== Password Hint ===" << endl;

        }
        cout << endl;

        cout << "Username: ";
        cin >> username;
        if(type == 1){

            cout << "Password: ";

            do{

                c = getch();

                if(c == 8 && pw.size() > 0){

                    pw = pw.substr(0,pw.size()-1);
                    cx -= 1;
                    screen.move(cx,cy);

                }else if (c != 13){

                    cout << "*";
                    pw += c;

                };

            } while (c != 13);

        };

        status = login(username, pw, type);

        switch(status){

            case 0: screen.clear();
                    cout << "ERROR: User doesn't exist." << endl;
                    cout << endl;
            break;
            case 1: usermenu(username);
            break;
            case 2: screen.clear();
                    cout << "ERROR: Username and password don't match." << endl;
                    cout << "Password hint: " << hintLookup(username) << endl;
                    cout << endl;

                    pw = "";

            break;
            case 3: do{

                        cout << "Password hint: " << hintLookup(username) << endl;
                        cout << endl;
                        cout << "Hit any key to login...";

                    } while (!getch());

                    printLogin(1);
            break;

        }
    } while (status != 1);

    return;
}

int login(string username, string pw, int type){

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

        if(actualPass == pw && type != 0){

            status = 1; // login successful

        } else if(type != 0){

            status = 2; // password mismatch

        } else {

            status = 3; // forgot password lookup only

        }

    }

    userFile.clear();
    userFile.close();

    return status;

}

std::string hintLookup(std::string username){

    string pwhint;
    string filename;

    // attempt to open user file
    filename = "users\\" + username + ".usr";

    ifstream userFile;

    userFile.open(filename.c_str());

    getline(userFile, pwhint); // skips first line of user file
    getline(userFile, pwhint);

    userFile.clear();
    userFile.close();

    return pwhint;

}

double highScore(std::string username){

    double score;
    string filename;
    string junk;

    // attempt to open user file
    filename = "users\\" + username + ".usr";

    ifstream userFile;

    userFile.open(filename.c_str());

    getline(userFile, junk); //
    getline(userFile, junk); // skips first two lines of user file
    userFile >> score;

    userFile.clear();
    userFile.close();

    return score;

}
