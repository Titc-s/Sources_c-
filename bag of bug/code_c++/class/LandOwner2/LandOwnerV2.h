//只声明函数
#include<bits/stdc++.h>
using namespace std;
class LandOwnerV2
{
    private:
     string name;
     long score;
     int cards[20];
public:
     LandOwnerV2(); // 构造函数的声明
     ~LandOwnerV2();      // 析构函数的声明


     void TouchCard(int); //声明摸牌方法
     void ShowScore();            //声明的显示积分方法


        

};