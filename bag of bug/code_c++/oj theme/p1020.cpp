#include<bits/stdc++.h>
using namespace std;
char line[2000];
int main()
{
    cin.getline(line,2000);
    int cur = 0, pos = 0, maxlen = 0, minlen = 200;
    int minpos, maxpos;
    int len = strlen(line);
    for (int i = 0; i < len;i++){
        if(isalpha(line[i]))
            cur++;
            else{
                if(cur>maxlen){

                    maxlen = cur;
                    maxpos = pos;
                }
                if(cur<minlen){
                    minlen = cur;
                    minpos = pos;
                }
                cur = 0;
                pos = i + 1;
            }
             if(cur>maxlen){

                    maxlen = cur;
                    maxpos = pos;
                }
                if(cur<minlen){
                    minlen = cur;
                    minpos = pos;
                }
                if(minlen=maxlen){
                    for (int i = minpos; isalpha(line[i]);i++)
                        cout << line[i];
                                 }
                else{
                    for(int i=maxpos)
                }
            
    }
}
