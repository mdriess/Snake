#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>

using namespace std;

/*  Login

    Description: Authenticates user for logged-in play

*/
void printLogin(int);

/*  Login authentication

    Description: Authenticates user for logged-in play and returns int
        response code. 1 = user and pass match, 2 = mismatch, 0 = user doesn't
        exist

*/
int login(std::string, std::string, int);

/*  Password hint

    Description: Authenticates user for logged-in play and returns int
        response code. 1 = user and pass match, 2 = mismatch, 0 = user doesn't
        exist

*/
std::string hintLookup(std::string);

/*  user high score

    Description: Looks up user's high score

*/
double highScore(std::string);



class User{
    string name;
    string pwd;
    string hint;
    int score;
    public:
        User(string , string);//used for new account
        User(string);//used for existing account
        ~User();
        string getName();
        bool checkPass(string);
        bool changePass(string,string);
        int getScore();
        bool setScore(int);
        string getHint();
};

#endif // USER_H_INCLUDED
