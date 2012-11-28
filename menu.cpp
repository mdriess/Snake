#include <iostream>
#include "menu.h"
#include "plotter.h"
#include "user.h"
#include "game.h"
#include "score.h"
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void loadscreen()//opening screen
{

    Plotter screen;
    screen.clear();
    screen.setColor(red);

    cout << "SNAKES IN THE CONSOLE" << endl;

    // we will want to beautify this page using
    // ascii art + plotter.cpp eventually

    cout << "                 __" << endl;
    cout << "     _______    /*_>-<" << endl;
    cout << " ___/ _____ \\__/ /" << endl;
    cout << "<____/     \\____/" << endl;
    cout << "Press any key to continue." << endl;
    cout << "Press ESC to exit." << endl;
    if(getch()==ESC)
        exit(0);
    mainmenu(screen);

// clear screen using plotter

    return;

}
void mainmenu(Plotter& screen)//main menu
{
    screen.clear();
    int ans;
    string name="=== MAIN MENU ===";
    string choices[]= {"Login","Create Account", "High Scores", "Anonymous Play"};
    int size=4;
    ans = menu(screen,name,choices,size);

    switch(ans)
    {
    case 0:
        userLogin(screen);
        break;
    case 1:
        createAccount(screen);
        break;
    case 2:
        highScoreList(screen);
        break;
    case 3:
        (Game()).playGame();
        break;
    default:
        loadscreen();
        break;
    }
    return;

}
void usermenu(Plotter& screen,User& username)//menu after user is logged in
{
    screen.clear();
    Game g;
    int ans;
    string name=username.getName();
    string score=username.getScore()+"";
    string title = "Welcome, "+name+"!\n";
    title = title+"Your high score: "+score+"\n";
    title = title+"=== USER MENU ===";
    string choices[]= {"Play Game","Change Password","Settings"};
    ans=menu(screen, title,choices,3);
    switch(ans)
    {
    case 0:
        g=Game(username);
        g.playGame();
        break;
    case 1:
        changePassword(screen,username);
        break;
    case 2:
        userSettings(screen,username);
        break;
    default:mainmenu(screen);
    };

}
int menu(Plotter&screen, string title, string ary[],int size)//template for menu selections
{

    int ind=0;
    char c='0';
    do
    {
        screen.clear();
        cout << title<<endl;
        for(int i=0; i<size; ++i)
        {
            if(ind==i)
            {
                screen.setColor(white);
            }
            cout << ary[i] << endl;
            if(ind==i)
            {
                screen.setColor(red);
            }
        }
        cout << "Press ESC to go back."<< endl;
        c=getch();
        if(c==DOWN)
        {
            ind++;
        }
        else if(c==UP)
        {
            ind--;
        }
        if(ind<0||ind>=size)
        {
            ind+=size;
            ind%=size;
        }
        if(c==ESC)//if we hit ESC, exit the menu.
        {
            c=ENTER;
            ind=-1;
        }

    }
    while(c!=ENTER);
    return ind;
}
void userLogin(Plotter&screen)//menu for login
{
    string username;
    string pw;
    string pwhint;
    bool done=false;
    int x=0, y=0;
    User u;
    screen.clear();

    do
    {
        cout << "=== Login ===" << endl;
        y++;//move down a line
        cout << "Username: ";
        cin >> username;
        y++;//move down a line
        cout << "Password: ";
        x=10;//move over to enter characters
        pw=enterPassword(screen,x,y);
        int result=login(username,pw);
        screen.clear();
        switch(result)
        {
        case 0:
            cout<<"User does not exist." <<endl;
            y=1;
            break;
        case 1:
            u=User(username);
            usermenu(screen,u);
            break;
        case 2:
            cout<<"Incorrect Password. Hint:"<<endl;
            cout<<hintLookup(username)<<endl;
            y=2;
            break;
        }
        if(result==1)
            done=true;
    }
    while(!done);



}
int login(string username, string pw)//checks login validity
{
    int status;
    string filename;
    string actualPass;
    // attempt to open user file
    filename = "users\\" + username + ".usr";
    ifstream userFile;
    userFile.open(filename.c_str());
    if(!userFile)
    {
        status = 0; // user doesn't exist
    }
    else
    {
        userFile >> actualPass;
        if(actualPass == pw)
        {
            status = 1; // login successful
        }
        else
        {
            status = 2; // password mismatch
        }
    }
    userFile.clear();
    userFile.close();

    return status;

}
string hintLookup(string username)//looks up the hint for this user
{

    string pwhint;
    string filename;

    // attempt to open user file
    filename = "users\\" + username + ".usr";

    ifstream userFile;

    userFile.open(filename.c_str());

    getline(userFile, pwhint); // skips first line of user file
    getline(userFile, pwhint);

    userFile.close();

    return pwhint;

}
int highScore(string username)//looks up the high score for this user
{
    string filename;
    int score;
    // attempt to open user file
    filename = "users\\" + username + ".usr";

    ifstream userFile;
    userFile.open(filename.c_str());

    getline(userFile,filename);//skip first 2 lines of file
    getline(userFile,filename);

    userFile>>score;

    userFile.close();
    return score;

}
void changePassword(Plotter&screen, User& username)//change password menu
{
    string oldPW,newPW,confirmPW,hint;
    screen.clear();
    int x=0;
    int y=0;

    cout << "Change Password for "<<username.getName()<<endl;y++;
    cout << "(Press ESC at any time to go back)" << endl;
    cout << "Password: ";x=10;
    oldPW=enterPassword(screen,x,y);
    if(oldPW=="")
        return;
    cout << "New Password: ";x=14;
    newPW=enterPassword(screen,x,y);
    if(newPW=="")
        return;
    cout << "Confirm New Password: ";x=22;
    confirmPW=enterPassword(screen,x,y);
    if(confirmPW=="")
        return;
    cout << "Enter new Password Hint: ";
    getline(cin,hint);

    if(newPW!=confirmPW)
    {
        cout << "New Passwords do not match!" << endl;
        cout << "Press any key to try again, or ESC to go back." << endl;
    }
    else if(username.changePass(oldPW,newPW))
    {

        cout << "Password successfully changed!" << endl;
        cout << "Press any key to continue..." <<endl;
    }
    else
    {
        cout << "Original Password incorrect!" << endl;
    }
    if(getch()==ESC)
    {
        changePassword(screen,username);
    }
    else
    {
        usermenu(screen,username);
    }
}
void userSettings(Plotter&screen,User&username)//user settings menu
{
    screen.clear();
    cout << "No user settings to be changed at this time."
         <<" Press any key to go back."<<endl;
    getch();
    usermenu(screen,username);
}
void highScoreList(Plotter&screen)//menu to display global high scores
{
    ifstream file("scores.dat");
    string name;
    int score,time;
    vector<Score>list;
    int size=0;
    Score s;

    screen.clear();

    while(file>>name>>score>>time)
    {
        list.push_back(Score(name,score,time));
        size++;
    }
    sort(list);
    file.close();
    cout << "=== HIGH SCORES ===" << endl << endl;
    cout << left << setw(20) << "Username" << setw(10) << "Score" << endl;
    cout <<         setw(20) << "========" << setw(10) << "=====" << endl;
    for(int i=0;i<10&&i<size;++i)
    {
        s=list.at(i);
        cout << (i+1) << ".";
        cout << setw(20) << s.name << setw(10) << s.score << endl;
    }

    cout << endl << "Press any key to go back!" << endl;

    getch();
    mainmenu(screen);
}
void createAccount(Plotter&screen)//create account screen
{
    screen.clear();
    string username,pw,confirm,hint;
    ifstream file;
    int x=0,y=0;
    do
    {
        file.close();
        file.clear();
        cout <<"Please enter desired username: ";
        cin >> username;y++;
        if(username == (""+ESC))
            return;
        file.open(("users\\"+username+".usr").c_str());
        if(file)
        {
            screen.clear();y=0;
            cout << "Username already taken. ";
        }
    }while(file);
    do
    {
        cout << "Please enter your password: ";x=28;
        pw = enterPassword(screen,x,y);
        cout << "Please re-enter your password: ";x=31;
        confirm = enterPassword(screen,x,y);
        if(pw!=confirm)
        {
            screen.clear();y=0;
            cout << "Passwords do not match." << endl;y++;
        }
    }while(pw!=confirm);
    getline(cin,hint);
    cout << "Please enter a Password Hint: ";
    getline(cin,hint);

    ofstream out;
    do
    {
        out.close();
        out.clear();
        out.open(("users\\"+username+".usr").c_str());
    }
    while(!out);
    out << pw << endl;
    out << hint << endl;
    out << 0 << endl;
    out.close();




    cout << "The user \"" << username << "\" has been created!"<< endl;
    User u(username);

    usermenu(screen,u);






}
string enterPassword(Plotter&screen,int &x,int &y)//method to enter a concealed password
{

    string pw="";
    char c;
    do
    {
        c = getch();
        if(c==ESC)
        {
            pw="";
            c=ENTER;
        }
        else if(c == BACK && pw.size() > 0)
        {

            pw = pw.substr(0,pw.size()-1);
            x -= 1;//move back since it was a backspace
            screen.move(x,y);
            cout << " ";
            screen.move(x,y);

        }
        else if (c != ENTER && c != BACK)
        {
            cout << "*";
            pw += c;
            x += 1;//move forward since it was a character
        }

    }
    while (c != ENTER);
    y++;//move down since we pressed enter
    cout << endl;
    return pw;
}
void resizeConsole(int x, int y)//resizes the console window
{

     SMALL_RECT tinyarea = {0,0,1,1};//the buffer size must be bigger than
            //the screen, so we make the screen really small
     SMALL_RECT DisplayArea = {0, 0, x, y};//size of screen we want
     COORD coord={x+1,y+1};//size of buffer we want
     HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);//the screen
     SetConsoleWindowInfo(out, TRUE, &tinyarea);//make the screen really small
     SetConsoleScreenBufferSize(out,coord);//set the buffer size
     SetConsoleWindowInfo(out, TRUE, &DisplayArea);//make the screen the size
                                                //we actually want
}
