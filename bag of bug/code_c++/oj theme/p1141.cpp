#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    string s;
    string e;
    while(cin>>s){
        if(s=="ENDOFINPUT")
            break;
        char ceaser[140001];
        gets(ceaser);
        int num = strlen(ceaser);
        for (int i = 0; i < num;i++)
        {
            if (ceaser[i]>='A'&&ceaser[i]<='Z'){
                cout << (char)((ceaser[i] - 'A' - 5 + 26) % 26 + 'A');
            }
            else
                cout << ceaser[i];
        }
        cout<< endl;
        cin >> e;
        getchar();
    }
  
}