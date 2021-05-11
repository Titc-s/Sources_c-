#include<bits/stdc++.h>
using namespace std;
double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
void print_result(double(*)(double,double),double,double);
void print_result(double(*ptrCalc)(double,double),double num1,double num2)
{
    double result = ptrCalc(num1, num2);
    cout << result << endl;
}


int main()
{
   // double (*ptrCalc)(double, double);
   auto ptrCalc = addition;
   double num1, num2;
   char op;
   cout << "请输入两个整数" << endl;
   cin >> num1 >> num2;
   cout << "请输入运算符";
   cin >> op;
   switch (op)
   {
   case '+':
       ptrCalc = addition;
       break;
   case '-':
       ptrCalc = subtraction;
       break;
   case '*':
       ptrCalc = multiplication;
       break;
   case '/':
       ptrCalc = division;
       break;
    }
    print_result(ptrCalc, num1, num2);
    return 0;
    
}
double addition(double num1,double num2)
{
    return num1 + num2;
}
double subtraction(double num1 , double num2)
{
    return num1 - num2;
}
double multiplication(double num1, double num2)
{
    return num1 * num2;
}
double division(double num1, double num2)
{
    if(num2 == 0){
        cout << "除数不能为0" << endl;
        return 0;
    }
    return num1 / num2;
}