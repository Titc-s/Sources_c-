#include <iostream>
using namespace std;

struct Chip
{
    int num;
    int state;
};

int judge(Chip *a, Chip *b)
{
    int count = 0;
    if (a->state == 1)
    {
        count = +b->state; //如果a是好的，判断b的结果与b一致
    }
    else if (a->state == 0)
    {
        count += (rand() % 2); //如果a是坏的，判断b可能好可能坏，随机产生
    }
    if (b->state == 1)
    {
        count += a->state;
    }
    else if (b->state == 0)
    {
        count += (rand() % 2);
    }
    return count;
}

vector<Chip *> oddTest(vector<Chip *> a)
{
}