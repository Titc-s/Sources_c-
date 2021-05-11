#include<bits/stdc++.h>
using namespace std;
/*
toName 聊天对象的名称
content 聊天内容
return
*/
string chatTo(const string &toName, const string &content);
string chatFrom(const string &fromName, const string &content);
int main()
{
    cout << "输入名称:";
    string toName, content;
    getline(cin, toName);
    cout << "输入聊天信息：";
    getline(cin, content);
    string chatMsg = chatTo(toName, content);
    cout << endl
         << chatMsg << endl;
    return 0;
}
string chatTo( const string &toName,const string& content)
{
    string msg = "※你说[" + toName + "]speak:" + content;
    return msg;
}
