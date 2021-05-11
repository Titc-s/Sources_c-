#include<bits/stdc++.h>
using namespace std;
class Computer{
    public:
        Computer();
        Computer( const int &core) { this->m_core = core; }
        void buy(int core)
        {

        }
        void SetCore(int core) { this->m_core = core; }
        int  GetCore() { return m_core; }

    private:
        int m_core;
};
class TestClass{}
void ConstDemo1()
{
    int num1 = 1024;
    const int num2 = num1;
    const int *ptr1_num1 = &num1;
    int const *ptr2_num1 = &num1;
    ptr1_num1 = &num2;
   
    
}
void ConstTest3(const Computer &computer)
{ 
    
}
const Computer&GetMax(const Computer&com1,const Computer &com2){
    Computer com3;
    if (com1.GetCore()>com2.GetCore())
{
    return com1;
}
return com2;
}