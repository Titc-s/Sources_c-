#include<bits/stdc++.h>
using namespace std;
class Integer
{
    public :
        Integer();
        Integer(int value) : m_value(value){}
        Integer operator+(Integer other);
        int IntValue() { return m_value; }

       virtual  ~Integer();
        protected:

        private:
            int m_value;      // 实际整型数字
};
 Integer::Integer():m_value(0)
 {

 }
Integer Integer::operator+(Integer other)
 {
     Integer result(this->m_value + other.m_value);
     return result; // 用来返回的结果对象
 }
 Integer::~Integer()
 {

 }
 void TestInteger();
 int main()
 {
     TestInteger();
     cout << "我哈哈" << endl;
     return 0;
  }
  void TestInteger()
  {
      Integer int1(1024), int2(2048), int3;
      int3 = int1 + int2;
      cout<< "结果为"<< int3.IntValue() << endl;
  }