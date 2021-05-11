#include<bits/stdc++.h>
using namespace std;
class LandOwner
{
    private:
    string m_NickName;
    string m_Sex;
    int m_Gold;
    long m_Exp;
    vector<int> packCards;   //默认的一副牌，从1-54；
    vector<int> cardsVec;   //当前玩家的手牌数组
    vector<int> currCards; //摸牌后牌库剩余的牌
    vector<int> surplusCards;

public :

    LandOwner();
    LandOwner(string);
    LandOwner(string, string,int,long);
    ~LandOwner();

    string GetNickName() { return m_NickName; }
    void SetNickName(string val) { m_NickName = val; }
    string GetSex() { return m_Sex; }
    void SetSex(string val) { m_Sex = val; }
    int GetGold() { return m_Gold; }
    void SetGold(int val) { m_Gold = val; }
    long GetExp() { return m_Exp; }
    void SetExp(long val) { m_Exp = val; }

    void TouchCard(int cardCount); //摸牌
    void ShowInfo();    
    void InitCards();         //初始化packCards和,surplusCards和currCards；
    void ShowCards(const vector<int>&);

protected:


};
LandOwner::LandOwner()
{
    SetNickName("默认地主");
    SetSex("保密");
    SetExp(0);
    SetGold(1000);
    InitCards();
    ShowCards(packCards);
    cout << "LandOwner()被调用" << endl;
}
LandOwner::LandOwner(string nickName):m_NickName(nickName)
{
    SetSex("保密");
    SetExp(0);
    SetGold(1000);
    InitCards();
    ShowCards(currCards);
    cout << "LandOwner(string)被调用" << endl;
}
LandOwner::LandOwner(string nickName, string sex, int gold, long exp) : m_NickName(nickName), m_Sex(sex), m_Gold(gold), m_Exp(exp)
{
    InitCards();
    ShowCards(packCards);
    cout << "LandOwner(string,string,int ,long)被调用" << endl;
}
void LandOwner::ShowInfo()
{
    cout << "昵称：" << GetNickName() << endl;
    cout << "性别：" << GetSex() << endl;
    cout << "金币：" << GetGold() << endl;
    cout << "经验：" << GetExp() << endl;
}
void LandOwner::InitCards()
{
    for (int i = 0; i < 54;i++){
        packCards.push_back(i + 1);
        surplusCards.push_back(packCards.at(i));
    }
    currCards.clear();
}
void LandOwner::ShowCards(const vector<int>& cards)
{
    for (int i = 0; i < cards.size();i++)
    {
        cout << cards[i] << ",";

    }
    cout << endl;
}
LandOwner::~LandOwner()
{
    cout << GetNickName() << "被释放" << endl;
}
int main()
{
    LandOwner *ptr_landOwner1 = new LandOwner();
    LandOwner *ptr_landOwner2 = new LandOwner("周扒皮");
    LandOwner *ptr_landOwner3 = new LandOwner("卢本伟");

    ptr_landOwner1->ShowInfo();
   
    ptr_landOwner2->ShowInfo();
    ptr_landOwner3->ShowInfo();

    delete ptr_landOwner1;
    delete ptr_landOwner2;
    delete ptr_landOwner3;
    return 0;
}