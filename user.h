#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED


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

#endif // USER_H_INCLUDED
