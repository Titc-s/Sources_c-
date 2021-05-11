#include<bits/stdc++.h>
using namespace std;
int c[400];
char a[400], b[400], n[400];
int lc,la,lb;
int main()
{
    while(gets(a)){
    int la = strlen(a);
    gets(b);
    int lb = strlen(b);
    if (la < lb||(la==lb&&strcmp(a,b)<0))
    {
        strcpy(n, a);
        strcpy(b, a);
        strcpy(a, b);
        cout << "-";

    }
    int aa[400] = {0}, bb[400] = {0};
    for (int i = 0; i < la - 1;i++)
    {
        aa[la - i] = a[i] - '0';

    }
    for (int i = 0; i <= lb - 1;i++)
    {
        bb[lb - i] = b[i] - '0';
    }
    int i = 1, x = 0;
    while (i <= la || i <= lb)
    {
        if(aa[la]==0)
            la--;
            if(aa[i]<bb[i])
            {
                aa[i + 1]--;
                aa[i] += 10;
            }
            c[i] = aa[i] - bb[i];
            i++;
            lc++;
    }
    bool temp = true;
    for (int i = lc; i >= 1;i--)
    {
        if(c[i]==0&&temp==true)
            continue;
            else
                temp = false;
            cout << c[i];
    }
    cout << endl;
}
    return 0;
}