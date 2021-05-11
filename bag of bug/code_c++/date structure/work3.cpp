#include<stdio.h>
#include<malloc.h>
#include<cstring>
#include<cstdlib>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int Status;
typedef struct{
    char *base;
    char *top;
    int stacksize;

} SqStack;

Status InitStack(SqStack &S){
    S.base = new char[STACK_INIT_SIZE];
    if(!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack &S){
    if(S.top==S.base)
        return TRUE;
     else
        return FALSE;
}

Status Push(SqStack &S,char e){
    if(S.top-S.base>=S.stacksize){
        return FALSE;
    }
    *S.top++ = e;
    return OK;
}

Status Pop(SqStack &S,char &e){
    if(S.top== S.base)
        return FALSE;
    e = *--S.top;
    return OK;
}

Status PalindromeNum(SqStack &S,char str[]){
    int len = strlen(str);
    int m = len / 2;
    int i;
    char temp;
    for (i = 0; i < m;i++)
        Push(S, str[i]);
    if(len%2==0){
        while (!StackEmpty(S) ){
            char e;
            Pop(S, e);
            temp = e;
            if (temp != str[i] )
                    return 0;
            else
                i++;
        }
    }
    else if(len%2!=0){
        i = i + 1;
        while(!StackEmpty(S)){
            char e;
            Pop(S, e);
            temp = e;
            if(temp!=str[i])
                return 0;
                else
                    i++;
        }
    }
    return OK;
}
int main(){
    SqStack S;
    InitStack(S);
    char str[20];
    scanf("%s", str);
    if(PalindromeNum(S,str))
        printf("Right\n");
        else
            printf("Wrong\n");
    return 0;
}