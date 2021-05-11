#include <stdio.h>
#include<stdlib.h>
int main(){
long i=0,n;
scanf("%ld",&n);
while (i<n){
n-=i;
i++;
}
if (i%2==0) printf("%d/%d",n,i+1-n);
else printf("%d/%d",i+1-n,n);
system("pause");
return 0;
} 