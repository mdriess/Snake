#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

struct Score
{
    int score;
    string name;
    int time;
    Score();
    Score(string,int,int);
    int compare(Score);
};

void sort(vector<Score>);
#endif // SCORE_H_INCLUDED
