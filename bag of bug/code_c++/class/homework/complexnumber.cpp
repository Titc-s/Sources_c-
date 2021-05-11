#include<bits/stdc++.h>
using namespace std;
typedef struct complexnum{
    float real, image;
}complexnum;
 complexnum Input(float a,float b)
 {
     complexnum c;
     c.real = a;
     c.image = b;
     return (c);
 }
 complexnum add(complexnum c1,complexnum c2)
 {
     complexnum sum;
     sum.real = c1.real + c2.real;
     sum.image = c1.image + c2.image;
     return (sum);
 }
 complexnum mul(complexnum c1,complexnum c2)
 {
     complexnum mul;
     mul.real = c1.real * c2.real - c1.image * c2.image;
     mul.image = c1.real * c2.image + c1.image * c2.real;
     return (mul);
 }
 complexnum div(complexnum c1,complexnum c2)
 {
  complexnum div;
  float part1,part2,part3,part4;
  part1 = c1.real * c2.real + c1.image * c2.image;
  part2 = c2.real * c2.real + c2.image * c2.image;
  part3 = c1.image * c2.real - c1.real * c2.image;
  part4 = c2.real * c2.real + c2.image * c2.image;
  if(part2!=0&&part4!=0)
  {
      div.real = part1 / part2;
      div.image = part3 / part4;
      return (div);
  }
  else{

      div.real = 0;
      div.image = 0;
      return (div);
      }
 }
      void printdivnum(complexnum c)
      {
          if(c.real==0&&c.image==0)
              cout << "0" << endl;
              if(c.real!=0&&c.image==0)
                  cout << c.real << endl;
                  if(c.real==0&&c.image!=0)
                      cout << c.image << "i" << endl;
                  if (c.real != 0 && c.image < 0)
                      cout << c.real << c.image << "i" << endl;
                      if(c.real!=0&&c.image>0)
                          cout << c.real << "+" << c.image << "i" << endl;
      }
 
int main()
{
    float a, b,c, d;
    cin >> a >> b >> c >> d;
    complexnum c1, c2, c3;
    c1 = Input(a, b), c2 = Input(c, d);
    c3=div(c1, c2);
    printdivnum(c3);
    return 0;
}
