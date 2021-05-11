#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE 1024


using namespace std;

int main()
{
    char buf[MAX_LINE];
    FILE *fp;
    int len;
    if((fp=fopen("D:\\bag of bug\\code_c++\\c++destruct\\sources\\1.txt","r"))==NULL){
        perror("fail to read");
        exit(1);
    }
    while(fgets(buf,MAX_LINE,fp)!=NULL)
    {
        len = strlen(buf);
        buf[len - 1] = '\0';
        cout << buf << len - 1 << endl;

    }
    return 0;
}