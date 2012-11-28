#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>

using namespace std;

class User{
    string name;
    string pwd;
    string hint;
    int score;
    public:
        User();
        User(string , string);//used for new account
        User(string);//used for existing account
        ~User();
        string getName();
        bool checkPass(string);
        bool changePass(string,string);
        int getScore();
        bool setScore(int);
        //string getHint();
};

#endif // USER_H_INCLUDED
