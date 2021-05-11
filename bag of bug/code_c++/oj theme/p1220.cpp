  #include<iostream>
  using namespace std;
  int v[50][3]={0},m[50]={0},p[50]={0};
  int n,k=0,solus=0;
  void sh(int c){
      if(c==k){
          solus++;
      }
      else {
         int cur=p[c];
         for(int i=0;i<8;i++){
             if(!v[i][0]&&!v[cur-i+8][1]&&!v[cur+i][2]){
                 m[cur]=i;
                 v[i][0]=v[cur-i+8][1]=v[cur+i][2]=1;
                 sh(c+1);
                 v[i][0]=v[cur-i+8][1]=v[cur+i][2]=0;
             }
         }    
     }
 }
 int main(){
     int x,i,j;
     for(i=0;i<8;i++){
         int flag=1;
         for(j=0;j<8;j++){
             cin>>x;
             if(x==1){
                 v[j][0]=v[i-j+8][1]=v[i+j][2]=1;
                 flag=0;
             }
         }
         if(flag){
            p[k++]=i;
         }
    }
    sh(0);
    cout<<solus;
    return 0;
 }