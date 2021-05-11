#include<bits/stdc++.h>
using namespace std;
 //hpp 文件一般包含实现的内联函数，通常用于模板类这种声明与实现共存的情况
 //.h 不是纯模板           .cpp作为函数实现文件
class LandOwnerV1
{
    public:
        string name; // 地主名称
        long score;//地主积分
        int cards[20];//地主手牌数
        public:
            LandOwnerV1(){} //实现了默认构造函数
           ~LandOwnerV1(){}// 析构函数
           //摸牌方法
            void TouchCard(int cardCount)//默认内联函数
            {
                cout << name << "摸了" << cardCount << "张牌"<< endl;   
            }
            void ShowScore(){
                cout << name << "当前积分为：" << score << endl;
            }
};
