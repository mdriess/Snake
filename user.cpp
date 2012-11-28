#include <iostream>
#include "user.h"
#include "menu.h"
#include <cstring>
#include "plotter.h"
#include <fstream>
#include <cstdlib>



using namespace std;



User::User()
{

    User("guest");
}

User::User(string n)
{
    name=n;
    ifstream file;
    file.open(("users\\"+name+".usr").c_str());
    getline(file,pwd);
    getline(file,hint);
    file>>score;
    file.close();
}

User::~User()
{
    ofstream file;
    file.open(("users\\"+name+".usr").c_str());
    file<<pwd << endl;
    file<<hint<<endl;
    file<<score<<endl;
    file.close();
}

string User::getName()
{
    return name;
}

bool User::checkPass(string s)
{
    return pwd.compare(s) == 0;
}

bool User::changePass(string oldP,string newP)
{
    bool ret=false;

    if(checkPass(oldP))
    {
        pwd=newP;
        ret=true;
    }
    return ret;
}

int User::getScore()
{
    return score;
}

bool User::setScore(int i)
{
    bool ret=false;
    if(i>score)
    {
        score=i;
        ret=true;
    }
    return ret;

}
