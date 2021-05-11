#include<bits/stdc++.h>
using namespace std;
class LandOwnerV3
{
    string name = "笨比";
    long score; // 积分
    int cards[20];

public:

    LandOwnerV3();
    ~LandOwnerV3();


     void ShowScore();
     //使用方法实现对成员变量的封装get/set方法
     void SetScore (long lScore){

         
         if (lScore < 0){
             score = 0;
             cout << " over " << endl;
         }else
         {
         score = lScore;
         }
     }
};
LandOwnerV3:: LandOwnerV3()
{

}
void LandOwnerV3:: ShowScore()
{
    cout << name << "得了" << score << "分" << endl;
}

LandOwnerV3::~LandOwnerV3()
{

}
int main()
{
LandOwnerV3 landOwner3;
landOwner3.SetScore (-100);
landOwner3.ShowScore();
return 0;
}