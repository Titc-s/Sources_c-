#include<iostream>
#include<stack>
#include<string>

using namespace std;

 int prio(char op){
     int priority;
     if(op=='*'||op=='/')
         priority = 2;
     if(op=='+'||op=='-')
         priority = 1;
     if(op=='(')
         priority = 0;
     return priority;
 }
 bool Trans(string &str,string &str1){
     stack<char> s;
     int i;
     for (i = 0; i < str.size();i++){
         if(str[i]>='0'&&str[i]<='9'){
             str1 += str[i];// 如果是数字，直接入栈
         }
         else {
             if(s.empty())   // 栈空则入栈
                 s.push(str[i]);
             else if (str[i]=='(') // 左括号入栈
                 s.push(str[i]);
             else if (str[i]==')'){
                while(s.top()!='('){
                    str1 += s.top();
                    s.pop();
                }
             s.pop();
         }
        else {
            while(prio(str[i])<=prio(s.top())){
                str1 += s.top();
                s.pop();
                if(s.empty())
                    break;
            }
            s.push(str[i]);
        }
     }
 }
 while(!s.empty()){
     str1 += s.top();
     s.pop();
 }
 return true;
 }
 int main()
 {
     string infix;
     string postfix;
     cout << "输入中缀表达式：" << infix << endl;
     cin >> infix;
     Trans(infix, postfix);
     cout << "后缀表达式为：" << postfix << endl;
     return 0;
 }