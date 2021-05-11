#include<iostream>
#include<string.h>
#include<algorithm>
#include<malloc.h>
#include<conio.h>
#include<stdio.h>
#include<Windows.h>

using namespace std;

#define Namesize 20
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATEE -1
#define NULL_KEY 0  // 无记录元素

int hashsize[] = {17, 19, 23, 29};  //存储容量
int m = 0;  // 表长

typedef struct
{
    int year, month, day;
} Data;

typedef struct
{
    char StuNum[5];
    Data borrow;
    Data back;
} ReaderNode;

typedef struct 
{
    Data data;
    string id;  // 书号
    char name[Namesize]; //书名
    char writer[Namesize]; // 作者
    int surplus ; //剩余数量
    int n_surplus; //现存量
    int total;//书的总量
    int key;// 书的编号（？）
    ReaderNode reader[10];  //记录解读该书的读者记录

} BookNode;

BookNode book[200];//图书数量

typedef struct
{
    BookNode *elem;
    int count; // 记录节点综述
} HashTable;

void InitHashTable(HashTable *H)
{
    int i;
    (*H).count = 0;
     m = hashsize[0];
   //  (*H).elem = (BookNode *)malloc(m*sizeof(BookNode));
     (*H).elem = new BookNode[m];
     for (i = 0; i < m;i++)
     {
         (*H).elem[i].key = NULL_KEY;
     }
}
 
unsigned Hash(int K)   // 哈希函数
{
    return K % m;
}

void collision (int *p,int d)//开放寻址法处理冲突
{
    *p = (*p + d) % m;
}

int SearchHash(HashTable H, int K, int *p, int *c) // 哈希表内查找数据
{
    *p = Hash(K);
    while (H.elem[*p].key != NULL_KEY && (K != H.elem[*p].key))
    {
        (*c)++;
        if (*c < m)
            collision(p, *c); // 继续查看下一地址
        else
            break;
    }
    if (K == H.elem[*p].key)
        return SUCCESS;
    else
        return UNSUCCESS;
}

int InsertHash(HashTable *H, BookNode e) // 插入哈希表
{
    int c, p;
    c = 0;
    if (SearchHash(*H, e.key, &p, &c))
        return DUPLICATEE; // 已经存在该数据
    else if (c < hashsize[0] / 2)
    {
        (*H).elem[p] = e;
        ++(*H).count;
        return 1;
    }
    return 0;
}

int DeleteHash(HashTable *H,BookNode e)// 删除结点
{
    int c, p;
    c = 0;
    if(SearchHash(*H,e.key,&p,&c))
    {
        (*H).elem[p].key = NULL_KEY;
        --(*H).count;
        return 1;
    }
    else
    {
        cout << "不存在要删除的内容！" << endl;
    }
    return 0;
}


void AddBook(HashTable *H) //添书
{
    BookNode e;
    int i, p, c;
    system("CLS"); //清屏
    cout << endl
         << endl
         << "**************************************************" << endl;
    cout << "\t你能在此目录下添加图书信息";
    cout << "\n**************************************************\n";
    cout << "\n\t    请输入书的编号(形如: 1***): ";
    cin >> e.key;
    getchar();
     if(SearchHash(*H,e.key,&p,&c))
    {
        cout << "\n\t该书已存在，请输入要添加的数量；";
        int add;
        cin >> add;
        (*H).elem[p].total = (*H).elem[p].total+add;
        (*H).elem[p].surplus =   (*H).elem[p].surplus+add;
        cout << "\n\t  添加成功！" << endl;
        Sleep(1000);
    }
    else{
    cout << "\n\t   请输入书名：  ";
    gets(e.name);
    cout << "\n\t    请输入该书作者: ";
    gets(e.writer);
    cout << "\n\t    请输入该书现库存量: ";
    cin >> e.surplus;
    cout << "\n\t    请输入该书总库存量: ";
    cin >> e.total;
    for (i = 0; i < 10; i++)
        (e.reader[i]).StuNum[0] = '\0'; // 初始化借书者，表示没有人借书。
    if (InsertHash(&(*H), e))
        cout << e.name << "现已添加成功" << endl;
    (*H).count++;
    }
}


void ShowBook(HashTable H)
{
    int i;
    system("CLS");
    cout << "\n\n**************************************************\n";
    cout << "\t你能在此目录查看图书信息";
    cout << "\n**************************************************\n";
    for (i = 0; i < m; i++)
        if (H.elem[i].key != NULL_KEY) // 若不为空
        {
            printf("图书编号：%d\n", H.elem[i].key);
            printf("书名： 《%s》\n", H.elem[i].name);
            printf("作者：  %s\n", H.elem[i].writer);
            printf("图书现存量： %d\n", H.elem[i].surplus);
            printf("图书总量  ： %d\n", H.elem[i].total);
            cout << "***************************************************\n";
        }
}

void Find(HashTable *H)
{
    int x, p, c;
    system("CLS");
    cout << "\n\n**************************************************\n";
    cout << "\t你能在此目录下按照书号查找图书信息";
    cout << "\n**************************************************\n";
    cout << "\n\t 请输入你想查的书的编号： ";
    scanf("%d%*c", &x); // 跳过输入字符
    if (SearchHash(*H, x, &p, &c))
    {
        printf("图书编号：%d\n", (*H).elem[p].key);
        printf("书名： 《%s》\n", (*H).elem[p].name);
        printf("作者：  %s\n", (*H).elem[p].writer);
        printf("图书现存量： %d\n", (*H).elem[p].surplus);
        printf("图书总量  ： %d\n", (*H).elem[p].total);
    }
    else
        cout << "该书未被收录" << endl;
}

void BorrowBook(HashTable *H)
{
    int i, k, x, f, t;
    cout << "\n\n**************************************************\n";
    cout << "\t你能在此目录下按照书号借阅图书";
    cout << "\n**************************************************\n";
    cout << "\n\t   请输入你想借的书的编号:  ";
    scanf("%d%*c", &x);
    if (SearchHash(*H, x, &k, &f))
    {
        cout << "\n\t 你想借这本书吗？（请输入Y 或者 N 代表你是否想借这本书）";
        printf("书名： 《%s》\n", (*H).elem[k].name);
        printf("作者：  %s\n", (*H).elem[k].writer);
        printf("图书现存量： %d\n", (*H).elem[k].surplus);
        printf("图书总量  ： %d\n", (*H).elem[k].total);
        t = getch();
        if (t == 'Y' || t == 'y')
        {
            if (((*H).elem[k].surplus) == 0)
                cout << "\n\t 对不起，该书剩余库存不足" << endl;
            else
            {
                for (i = 0; i < 10; i++)
                    if (((*H).elem[k].reader[i]).StuNum[0] == '\0')
                        break;
                cout << "\n\t    请输入你的借阅号（学号）：";
                cin >> ((*H).elem[k].reader[i].StuNum);
                cout << "\n\t  请输入借阅日期：";
                cout << "\n\t  年： ";
                cin >> (((*H).elem[k].reader[i]).borrow.year);
                cout << "\t    月： ";
                cin >> (((*H).elem[k].reader[i]).borrow.month);
                cout << "\t    日： ";
                cin >> (((*H).elem[k].reader[i]).borrow.day);

                cout << "\n\t  请输入应还日期： ";
                cout << "\n\t  年：  ";
                cin >> (((*H).elem[k].reader[i]).back.year);
                cout << "\t  月：  ";
                cin >> (((*H).elem[k].reader[i]).back.month);
                cout << "\t  日：  ";
                cin >> (((*H).elem[k].reader[i]).back.day);
                (*H).elem[k].surplus--;
                cout << "\n\t 你成功借阅了该书！";
            }
        }
    }
    else
        cout << "\n\t   这本书未被收录\n";
}

void ReturnBook(HashTable *H)
{
    int i, k, x, f, t, j;
    int year, month, day, d;
    float pay;
    char temp[20];
    system("CLS");
    cout << "\n\n**************************************************\n";
    cout << "\t你能在此目录下按照书号归还图书";
    cout << "\n**************************************************\n";
    cout << "\n\t 请输入你还的书： ";
    scanf("%d%*c", &x);
    if (SearchHash(*H, x, &k, &f))
    {
        cout << "\n\t   你是否确定要归还此书？（请输入Y 或者 N 代表你是否想归还这本书）";
        printf("书名： 《%s》\n", (*H).elem[k].name);
        printf("作者：  %s\n", (*H).elem[k].writer);
        printf("图书现存量： %d\n", (*H).elem[k].surplus);
        printf("图书总量  ： %d\n", (*H).elem[k].total);
        t = getch();
        if (t == 'Y' || t == 'y')
        {
            cout << "\n\t  请输入你的借书证号： ";
            cin >> temp;
            j = 0;
            for (i = 0; i < 5; i++)
            {
                if (!(strcmp(temp, ((*H).elem[k].reader[i]).StuNum))) //查看是否已经借阅图书
                {
                    j = 1;
                    break;
                }
            }
            if (j == 0)
            {
                cout << "\n\t  你没有未归还的图书.";
                return;
            }
            cout << "\n\t  请输入今天的日期：";
            cout << "\n\t   年";
            cin >> year;
            cout << "\n\t   月";
            cin >> month;
            cout << "\n\t   日";
            scanf("%d%*c", &day);
            d = 0;
            if (year < ((*H).elem[k].reader[i].back.year))
                d = 1; //判断是否已经过了还书日期  d= 1 ，还没过期  ,d=0,已经过期
            if (year <= ((*H).elem[k].reader[i]).back.year && month < ((*H).elem[k].reader[i].back.month))
                d = 1;
            if (year <= ((*H).elem[k].reader[i]).back.year && month < ((*H).elem[k].reader[i].back.month) && day < ((*H).elem[k].reader[i]).back.day)
                d = 1;
            if (d == 0)
            {
                printf("\n\t    你在 %d-%d-%d 借了这本书", ((*H).elem[k].reader[i]).borrow.year, ((*H).elem[k].reader[i]).borrow.month, ((*H).elem[k].reader[i]).borrow.day);
                printf("\n\t    你应该在   %d-%d-%d 还这本书", ((*H).elem[k].reader[i]).back.year, ((*H).elem[k].reader[i]).back.month, ((*H).elem[k].reader[i]).back.day);
                printf("\n\t    今天是        %d-%d-%d", year, month, day);
                cout << "\n\n\t  还书期限已过！请尽快还书！";
                pay = (year - ((*H).elem[k].reader[i]).back.year) * 365 + (month - ((*H).elem[k].reader[i]).back.month) * 30 + (day - ((*H).elem[k].reader[i]).back.day);
                cout << "\n\t  你还需额外支付" << 0.1 * pay << "元(一天一角钱，从还书期限日开始，上不封顶)";
            }
            ((*H).elem[k].reader[i].StuNum[0] = '\0');
            (*H).elem[k].surplus++;
            cout << "\t\n  成功归还本书:)" << endl;
        }
    }
    else
        cout << "未查到与此书有关的记录" << endl;
}

/*void SaveBook(HashTable H)
{
    FILE *fp1;
    int i;
    fp1 = fopen("record.txt", "w");
    fprintf(fp1, "=============== 图书信息记录表 =================\n");
    for (i = 0; i < m; i++)
    {
        if (H.elem[i].key != NULL_KEY)
        {
            fprintf(fp1, "============================================\n");
            fprintf(fp1, "图书编号:%d\n", H.elem[i].key);
            fprintf(fp1, "书名:%s\n", H.elem[i].name);
            fprintf(fp1, "作者:%s\n", H.elem[i].writer);
            fprintf(fp1, "现库存量:%d\n", H.elem[i].surplus);
            fprintf(fp1, "总库存量:%d\n", H.elem[i].total);
        }
        fprintf(fp1, "**************************************************\n");
        fclose(fp1);
        printf("\n\n成功储存!你能在record.txt找到相应纪录\n");
        printf("**************************************************\n");
    }
}
*/

void DeleteBook(HashTable H)
{
    int x, p, c, t;
    system("CLS");
    cout << "\n\n**************************************************\n";
    cout << "\t你能在此目录下按照书号删除图书信息";
    cout << "\n**************************************************\n";
    cout << "\n\t 请输入你想删除的书的编号： ";
    scanf("%d%*c", &x);
    if(SearchHash(H,x,&p,&c))

    {
        cout << "\n\t  你确定要删除这本书吗？（Y/N）" << endl;
         printf("图书编号：%d\n", H.elem[p].key);
            printf("书名： 《%s》\n", H.elem[p].name);
            printf("作者：  %s\n", H.elem[p].writer);
            printf("图书现存量： %d\n", H.elem[p].surplus);
            printf("图书总量  ： %d\n", H.elem[p].total);
    }
    else
        cout << "未找到您想要删除的书目！ \n";
    t = getch();
    if(t=='Y'||t=='y')
    {
        H.elem[p].key = NULL_KEY;
        cout << "成功删除此书！\n";
    }

}

void menu(void)
{
    system("CLS");
    cout << "*****************************************************" << endl;
    cout << "*** ***                图书管理系统            *** ***" << endl;
    cout << "*****************************************************" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\n\n\t  选择你需要操作的功能：\n";
    cout << "\t\t 1、采编入库\n";
    cout << "\t\t 2、显示已有图书信息\n";
    cout << "\t\t 3、查找图书信息\n";
    cout << "\t\t 4、删除图书信息\n";
    cout << "\t\t 5、借阅图书\n";
    cout << "\t\t 6、归还图书\n";
    // cout << "\t\t 7、保存图书到指定文件中\n";
    cout << "\n********************************************************" << endl;
}

int main()
{
    int  i, c;
    //int year, month, day;
    BookNode book;
    HashTable H;
    system("CLS");
    cout << "*****************************************************" << endl;
    cout << "*** ***                图书管理系统            *** ***" << endl;
    cout << "*****************************************************" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "*** ***          欢迎使用图书管理系统           *** ***" << endl;
    cout << "\n\n\t\t\t  按任意键进入主菜单\n";
   // getchar();
    InitHashTable(&H);
    while(1)
    {
        menu();
        cout << "请选择你需要的操作！（输入相关号码）";
        cin >> c;
        getchar();
        switch (c)
        {
        case 1:
            AddBook(&(H));
            break;
        case 2:
            ShowBook((H));
            break;
        case 3:
            Find(&(H));
            break;
        case 4:
            DeleteBook(H);
            break;
        case 5:
            BorrowBook(&(H));
            break;
        case 6:
            ReturnBook(&(H));
            break;
        // case 7:
        //     SaveBook((H));
        //     break;
        default:
            cout << "输入的操作序号无效！" << endl;
        }
        cout<<"输入ENTER键返回主菜单\n";
        getchar();
        system("CLS");
    }
}
