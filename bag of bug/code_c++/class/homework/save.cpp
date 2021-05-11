#include<bits/stdc++.h>
using namespace std;
int main()
{
    char Name[20], o_Name[20];
    cout << "输入文本名:";
    cin >> Name;
    cout << "输入二进制名：";
    cin >> o_Name;
    fstream ins, outs;
    outs.open(o_Name, ios_base::out | ios_base::binary);
    ins.open(Name, ios_base::in | ios_base::binary);
    if(ins){
        int text[1000];
        int t = 0;
        while(!ins.eof())
        {
            ins.read((char *)text, 1000);
            t = ins.gcount();
            outs.write((char *)text, t);
        }
        ins.close();
        outs.close();
    }
    else
        cout << "Error!" << endl;
    return 0;
}