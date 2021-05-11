#include<stdio.h>
  int main()
   {
         int i,a,b,c;
         i = 0;
         while(i<100) {
         printf("Enter numbers: ");
         scanf("%d %d %d",&a,&b,&c);
         if(a>b)
               {
               if(a>c) 
                printf("max. a=%d\n",a);
               else if(a==c) 
                 printf("max. a=c=%d\n",c);
                     else 
                  printf("max. c=%d\n",c);
               }
         else{
               if(a==b)
                   {
               if(a>c)  
                 printf("max. a=b=%d\n",a);
               else
                if(a==c)  
                  printf("max. a=b=c=%d\n",c);
                     else 
                       printf("max. c=%d\n",c);  
                     }
              else{ 
                  if(b>c) 
                printf("max. b=%d\n",b);
                else 
                 if(b==c)  
                    printf("max. b=c=%d\n",b);
                      else
                        printf("max. c=%d\n",c);
      	    }
             }
           i++;
           }
           return 0;
     }
