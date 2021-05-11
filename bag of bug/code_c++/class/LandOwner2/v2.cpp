//只声明函数
#include<bits/stdc++.h>
using namespace std;
class LandOwnerV2
{
   private:
       string name = "fuck boy";
       long score;
       int cards[20];

   public:
       LandOwnerV2();  // 构造函数的声明
       ~LandOwnerV2(); // 析构函数的声明

       void TouchCard(int); //声明摸牌方法
       void ShowScore();    //声明的显示积分方法
};
LandOwnerV2::LandOwnerV2()
{

}


// 实现摸牌方法；
void LandOwnerV2::TouchCard(int cardCount)
{
  cout << name << "摸了" << cardCount << "张牌"<< endl;   
}

LandOwnerV2::~LandOwnerV2()
{

}
int main()
{
LandOwnerV2 landOwner2;


landOwner2.TouchCard(2);
return 0;
}