#include<iostream>
#include<string>

using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1

typedef int Status;
typedef struct{
    char *base;
    char *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack &S){
    S.base = new char[STACK_INIT_SIZE];
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return true;
}

Status StackEmpty(SqStack &S){
    if(S.top == S.base)
        return true;
    else
        return false;
}

Status Push(SqStack &S,char e){
if(S.top - S.base>= S.stacksize)
    return false;
*S.top++ = e;
return true;
}

Status GetTop(SqStack &S){
    char *temp = S.top;
    if(S.top == S.base)
        return false;
    return *--temp;
}

Status Pop(SqStack &S){
    if(S.top== S.base)
        return false;
         *--S.top;
         return true;
}
    
int prio(char op){
    int priority;
     if(op=='*'||op=='/')
         priority = 2;
     if(op=='+'||op=='-')
         priority = 1;
     if(op=='(')
         priority = 0;
     return priority;
} //设置字符优先级
bool Trans(string &str,string &str1)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < str.size();i++){
        if((str[i]>='0'&&str[i]<='9')||(str[i]>='a'&&str[i]<='z')){
            str1 += str[i]; // 如果是数字，直接入栈
        }
        else {
            if(StackEmpty(S))
                Push(S, str[i]);
            else if (str[i] =='(')
                Push(S,str[i]);
            else if (str[i] ==')'){
                while(GetTop(S)!='('){
                    str1 += GetTop(S);
                    Pop(S);
                }
                Pop(S);
            }
            else{
                while(prio(str[i])<=prio(GetTop(S))){
                    str1 += GetTop(S);
                    Pop(S);
                    if(StackEmpty(S))
                        break;
                }
                Push(S, str[i]);
            }
        }
    }
    while(!StackEmpty(S)){
        str1 += GetTop(S);
        Pop(S);
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

//1+2*3+(4*5+6)*7 测试用