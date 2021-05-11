```c++
#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>

#include<string.h>

#include<conio.h>

#define SUCCESS 1

#define UNSUCCESS 0

#define DUPLICATE -1

#define NULL_KEY 0//无记录元素 

int hashsize[]={17,19,23,29};//存储容量 

int m=0;//表长 

typedef struct       

{ int year;      

  int month;     

  int day;       

}data;

typedef struct     

{

  char num[5];      //读者编号记录 

  data  bro;          

  data  back;         

}ReaderNode;

typedef struct       

{

  char title[15];      

  char writer[15];     

  int current;     

  int total;  

  int key;                 //书的编号       

  ReaderNode reader[10];   //记录借读该书的读者记录 

}BookNode;

typedef struct

{

        BookNode *elem; 

        int count;         //记录节点中的总数    

}HashTable;

 

void InitHashTable(HashTable *H)

{ 

   int i;

   (*H).count=0;  

   m=hashsize[0];

   (*H).elem=(BookNode *)malloc(m*sizeof(BookNode));

   for(i=0;i<m;i++)

     (*H).elem[i].key=NULL_KEY; 

}

unsigned Hash(int K)//哈希函数,自己设定

 {  

   return K%m;

 }

 

 void collision(int *p,int d) // 开放定址法处理冲突 

 { 

   *p=(*p+d)%m;

 }

 

int SearchHash(HashTable H,int K,int *p,int *c)//p为数据的地址位置，返回 

 { 

   *p=Hash(K); 

   while(H.elem[*p].key != NULL_KEY && (K != H.elem[*p].key))

   { 

     (*c)++;

     if(*c<m)

       collision(p,*c); //下一地址 

     else

       break;

   }

   if (K  ==  H.elem[*p].key)

     return SUCCESS; 

   else

     return UNSUCCESS; 

 }

int InsertHash(HashTable *H,BookNode e)

{

   int c,p;

   c=0;

   if(SearchHash(*H,e.key,&p,&c))  

     return DUPLICATE;

   else if(c<hashsize[0]/2) 

   { 

     (*H).elem[p]=e;

     ++(*H).count;

     return 1;

   }

   return 0;

}

 

int DeleteHash(HashTable *H,BookNode e)

{

   int c,p;

   c=0;

   if(SearchHash(*H,e.key,&p,&c))  

   {

       (*H).elem[p].key=NULL_KEY;

       --(*H).count; 

       return 1;                               

   }

   else

   { 

        printf("不好意思，不存在\n");

   }

   return 0;

}

 

void AddBook(HashTable *H)

{

      BookNode e;

      int i;

      system("CLS");

      printf("\n\n**************************************************\n");

      printf("\t你能在此目录下添加图书信息");

      printf("\n**************************************************\n");

      printf("\n\t    请输入书的编号(形如: 1***): ");

      scanf("%d",&e.key);

      getchar();

      printf("\n\t    请输入书名: ");    

      gets(e.title);

      printf("\n\t    请输入该书作者: ");

      gets(e.writer);

      printf("\n\t    请输入该书现库存量: ");

      scanf("%d",&e.current);

      printf("\n\t    请输入该书总库存量: ");

      scanf("%d%*c",&e.total);

      for(i=0;i<10;i++)

      (e.reader[i]).num[0]='\0';   //用'\0'来初始化借该书的读者证号，表示一开始时没人借书

      if(InsertHash(&(*H),e))

      printf("图书添加成功！\n");

      (*H).count++;  

}

void ShowBook(HashTable H)

{

   int i;

   system("CLS");

   printf("\n\n**************************************************\n");

   printf("\t你能在此目录查看图书信息");

   printf("\n**************************************************\n");

   for(i=0;i<m;i++)

     if(H.elem[i].key != NULL_KEY) /* 有数据 */

     {

          printf("图书编号：%d\n",H.elem[i].key);

          printf("书名： 《%s》\n",H.elem[i].title);

          printf("作者：  %s\n",H.elem[i].writer);

          printf("图书现存量： %d\n",H.elem[i].current);

          printf("图书总量  ： %d\n",H.elem[i].total);

          printf("***************************************************\n");

     }

}

void Find(HashTable *H)

{

     int x,p,c;

     system("CLS");

     printf("\n\n**************************************************\n");

     printf("\t你能在此目录下按编号查找图书信息");

     printf("\n**************************************************\n");      

     printf("\n\t    请输入你想查找的书的编号: ");

     scanf("%d%*c",&x);

     if(SearchHash(*H,x,&p,&c))

     {

          printf("图书编号：%d\n",(*H).elem[p].key);

          printf("书名： 《%s》\n",(*H).elem[p].title);

          printf("作者：  %s\n",(*H).elem[p].writer);

          printf("图书现存量： %d\n",(*H).elem[p].current);

          printf("图书总量  ： %d\n",(*H).elem[p].total);               

     }

     else

         printf("对不起，不存在该书！\n");    

 

}

void BorrowBook(HashTable *H)

{

  int i,k, x, f,t;

  system("CLS");

  printf("\n\n**************************************************\n");

  printf("\t你能在此目录下按编号借阅图书");

  printf("\n**************************************************\n");

  printf("\n\t    请输入你想借的书编号: ");

  scanf("%d%*c",&x);

  if(SearchHash(*H,x,&k,&f))   

  {

        printf("\n\t    你想借这本书吗 ?(y/n)");

        printf("\n\t    书名:  《%s》",(*H).elem[k].title);

        printf("\n\t    作者:   %s",(*H).elem[k].writer);

        printf("\n\t    现库存量:  %d",(*H).elem[k].current);

        printf("\n\t    总库存量:  %d",(*H).elem[k].total);

        t=getch();

        if(t=='y'||t=='Y')

        {

             if( ((*H).elem[k].current)==0) printf("\n\t对不起，这本书已经被借光了...");

             else

             {

                  for(i=0;i<10;i++)     

                       if( ((*H).elem[k].reader[i]).num[0]=='\0') break;

                  printf("\n\t    请输入你的借书证号: ");  

                  scanf("%s",((*H).elem[k].reader[i]).num);

                  printf("\n\t    请输入借书日期: "); //输入借书日期

                  printf("\n\t    年:  ");

                  scanf("%d",&(((*H).elem[k].reader[i]).bro.year));

                  printf("\t      月: ");

                  scanf("%d",&(((*H).elem[k].reader[i]).bro.month));

                  printf("\t       日:   ");

                  scanf("%d",&(((*H).elem[k].reader[i]).bro.day));

 

                  printf("\n\t    输入应还书日期: "); //输入应还书日期

                  printf("\n\t    年:  ");

                  scanf("%d",&(((*H).elem[k].reader[i]).back.year));

                  printf("\t      月: ");

                  scanf("%d",&(((*H).elem[k].reader[i]).back.month));

                  printf("\t       日:   ");

                  scanf("%d%*c",&(((*H).elem[k].reader[i]).back.day));

 

                  (*H).elem[k].current--;        //现存书量减1

                  printf("\n\t    你已借了该书.");

             }

        }

 

     }

  else printf("\n\t    这本书不存在！\n");    

}

void ReturnBook(HashTable *H)

{

  int i,k, x, f,t,j;

  int year,month,day,d;

  float pay;

  char temp[20];

  system("CLS");

  printf("\n\n**************************************************\n");

  printf("\t你能在此目录下按编号归还图书");

  printf("\n**************************************************\n");

  printf("\n\t    请输入你还的书: ");

  scanf("%d%*c",&x);

  if(SearchHash(*H,x,&k,&f))

  {

      printf("\n\t    你想还这本书吗 ?(y/n)");

      printf("\n\t    书名:    《%s》",(*H).elem[k].title);

      printf("\n\t    作者:     %s",(*H).elem[k].writer);

      printf("\n\t    现库存量:  %d",(*H).elem[k].current);

      printf("\n\t    总库存量:  %d",(*H).elem[k].total);

      t=getch();

      if(t=='y'||t=='Y')

      {

          printf("\n\t    请输入你的借书证号: ");

          scanf("%s",temp);

          j=0;

          for(i=0;i<5;i++)

          {

           if(!(strcmp(temp,((*H).elem[k].reader[i]).num))) {j=1;break;} //查看是否有借书

          }

          if(j==0) 

          { printf("\n\t    你没有借书.");return;}  //该借书证号的人没借书

          printf("\n\t    今天是:");  

          printf("\n\t    年:  ");

          scanf("%d",&year);

          printf("\t      月: ");

          scanf("%d",&month);

          printf("\t       日:   ");

          scanf("%d%*c",&day);

          d=0;

          if(year<((*H).elem[k].reader[i]).back.year) d=1; //判断是否已过了还书日期,d=1还没过期，d=0过期

          if(year<=((*H).elem[k].reader[i]).back.year && month<((*H).elem[k].reader[i]).back.month) d=1;

          if(year<=((*H).elem[k].reader[i]).back.year && month<=((*H).elem[k].reader[i]).back.month && day<((*H).elem[k].reader[i]).back.day) d=1;

          if(d==0)

          {

            pay=(year-((*H).elem[k].reader[i]).back.year)*365+(month-((*H).elem[k].reader[i]).back.month)*30+(day-((*H).elem[k].reader[i]).back.day);

                printf("\n\t    你在 %d-%d-%d 借了这本书",((*H).elem[k].reader[i]).bro.year,((*H).elem[k].reader[i]).bro.month,((*H).elem[k].reader[i]).bro.day);  

            printf("\n\t    你应该在   %d-%d-%d 还这本书",((*H).elem[k].reader[i]).back.year,((*H).elem[k].reader[i]).back.month,((*H).elem[k].reader[i]).back.day);

            printf("\n\t    今天是        %d-%d-%d",year,month,day);

            printf("\n\n\t  所以你超出了还书日期");

            printf("\n\t    你应该被罚款 %2.1f 元.",0.1*pay); //过期一天还1角钱

          }

          ((*H).elem[k].reader[i]).num[0]='\0'; //已还，清除该读者借书记录

          (*H).elem[k].current++;  //现存书量加1

          printf("\n\t  你已经还了这本书.\n");

       }

 

  }

  else printf("\n\t  你要还一本没库存的书 ???\n");  

     

}

void SaveBook(HashTable H){

        FILE *fp1; 

        int i;      

        fp1=fopen("record.txt","w");

        fprintf(fp1,"=============== 图书信息记录表 =================\n");       

        for(i=0;i<m;i++)

        {   

            if(H.elem[i].key != NULL_KEY)

            {

                             fprintf(fp1,"============================================\n");

                             fprintf(fp1,"图书编号:%d\n",H.elem[i].key);

                             fprintf(fp1,"书名:%s\n",H.elem[i].title);

                             fprintf(fp1,"作者:%s\n",H.elem[i].writer);

                             fprintf(fp1,"现库存量:%d\n",H.elem[i].current);

                             fprintf(fp1,"总库存量:%d\n",H.elem[i].total);

            }

        }

        fprintf(fp1,"**************************************************\n");

        fclose(fp1);

        printf("\n\n成功储存!你能在record.txt找到相应纪录\n");

        printf("**************************************************\n");

}

void DeleteBook(HashTable H)

{

    int x,p,c,t;

     system("CLS");

     printf("\n\n**************************************************\n");

     printf("\t你能在此目录下按编号删除图书信息");

     printf("\n**************************************************\n");      

     printf("\n\t    请输入你想删除的书的编号: ");

     scanf("%d%*c",&x);

     if(SearchHash(H,x,&p,&c))

     {

          printf("\n\t    你想删除这本书吗 ?(y/n)\n");

          printf("图书编号：%d\n",(H).elem[p].key);

          printf("书名： 《%s》\n",(H).elem[p].title);

          printf("作者：  %s\n",(H).elem[p].writer);

          printf("图书现存量： %d\n",(H).elem[p].current);

          printf("图书总量  ： %d\n",(H).elem[p].total);               

     }

     else

         printf("对不起，不存在该书！\n"); 

     t=getch();

      if(t=='y'||t=='Y')

      {

           (H).elem[p].key=NULL_KEY;

           printf("删除成功！\n");                  

      }

       

}

void menu(void)

{

        system("cls");

        system("color  aa");//改变颜色 

        system("cls");

        printf("*****************************************************************************\n");

        printf("*****************************************************************************\n");

        printf("************                 图书管理系统            ************************\n");

        printf("*****************************************************************************\n");

        printf("*****************************************************************************\n");

        printf("\n\n\t选择你需要操作的功能:(现无记录，请先添加信息)\n");

        printf("\n");

        printf("\t\t1.添加图书信息\n");

        printf("\t\t2.显示图书信息\n");

        printf("\t\t3.查找图书信息\n");

        printf("\t\t4.删除图书\n");

printf("\t\t5.借阅图书\n");

        printf("\t\t6.归还图书\n");

        printf("\t\t7.保存图书信息到指定文件中\n");

        printf("\n**************************************************\n");     

}

int main()

{

        int n,i,c;

        int year,month,day;

        BookNode book;

        HashTable H;

        system("cls");

        system("color  5e");//改变颜色 

        system("cls");

        printf("********************************* 图书管理系统 *********************************\n");

        printf("********************************* 软件工程     *********************************\n");

        printf("********************************* 丁洋         *********************************\n");

        printf("********************************* 07           *********************************\n");

        printf("\n\n\t\t\t\t欢迎您！！！\n");

        printf("请按ENTER进入主菜单\n");

        getchar();

        InitHashTable(&H);        

        while(1)

         {

                menu();

                printf("选择你需要操作的功能号码:");

                scanf("%d",&c);

                getchar();

                switch(c)

                {

                         case 1:

                              AddBook(&(H));break;

                         case 2:

                              ShowBook((H));break;

                         case 3:

                              Find(&(H));break;

                         case 4:

                              DeleteBook(H);break;

                         case 5:

                              BorrowBook(&(H));break;

                         case 6:

                              ReturnBook(&(H));break;

                         case 7:

                              SaveBook((H));break;  

                         default : printf("Enter error!!\n");        

                }

                printf("请按ENTER返回主菜单\n");

                getchar();

                system("CLS");

         }     

}
```

