
#include<bits/stdc++.h>
using namespace std;
class Cat
{
public:
Cat(const unsigned int _CatID)
{
CatID = _CatID;
++CountOfCats; 
}
static int GetHowMany();
unsigned int GetCatID()
{
return CatID;
}
private:
unsigned int CatID;
static int CountOfCats;
};


int Cat::CountOfCats = 0;
int Cat::GetHowMany()
{
return CountOfCats;
}


int main()
{
Cat a1(100), a2(101);
cout <<"CatID："<< a1.GetCatID() << endl;
cout << "CountOfCats：" << a1.GetHowMany() << endl;
cout << "CatID：" << a2.GetCatID() << endl;
cout << "CountOfCats：" << a2.GetHowMany() << endl;
system("pause");
return 0;
}