#include "score.h"


Score::Score()
{
    Score("",0,0);
}
Score::Score(string n,int s,int t)
{
    name=n;
    score=s;
    time=t;
}
int Score::compare(Score s)
{
    int ret=0;
    if(score>s.score)
        ret=1;
    else if(score<s.score)
        ret=-1;
    else if(time<s.time)
        ret=1;
    else if(time>s.time)
        ret=-1;
    return ret;
}

void sort(vector<Score>list)
{
    for(int i=0;i<(int)list.size();++i)
    {
        int ind=i;//index of maximum element
        for(int j=i;j<(int)list.size();++j)
        {
            if(list.at(j).compare(list.at(ind))>0)
                ind=j;
        }
        swap(list.at(i),list.at(ind));
    }
}
