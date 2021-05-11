#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct page
{
    int page_id;
    int opt_time;// 最长未被使用时间
    int lru_time;// 有多久未被使用？
} page;

int merge_time;
int random_num[50];
int count = 0;
vector<page> page_in;
page temp;
void random_()
{
    int i = 1;
    int m;
    random_num[0] = rand() % (319 - 0 + 1) + 0;
    m = random_num[0];
    while(i<50)
    {
        random_num[i] = ++m;
        i++;
        if(i>=50)
            break;
        random_num[i] = rand() % (m - 1 - 0 + 1) + 0;
        m = random_num[i];
        i++;
        if(i>=50)
            break;
        random_num[i] = ++m;
        i++;
        if(i>=50)
            break;
        random_num[i] = rand() % (319 - m + 2) + m + 1;
        m = random_num[i];
        i++;
    }
}

void page_print()
{
    cout << endl
         << "内存内页面为：";
    for (int k = 0; k < page_in.size();k++)
        cout << " " << page_in[k].page_id;
}

int in_memory(int id)
{
    bool sign = 0;
    for (int i = 0; i < page_in.size();i++)
    {
        if(id/10==page_in[i].page_id)
        {
            sign = 1;
            break;

        }
    }
    return sign;
}

int is_max()  //判断内存是否满 
{
    bool sign = 0;
    if(page_in.size()==4)
        sign = 1;
    return sign;
}

void FIFO() // 先进先出
{
    merge_time = 0;
    for (int i = 0; i < 50;i++){
        page_print();
        if(in_memory(random_num[i]))
        {
            cout << "\t\t执行第" << i << "条指令，指令为：" << random_num[i] << endl;
            continue;
        }
        else{
            if(is_max())
            {
                merge_time++;
                page_in.erase(page_in.begin());
                temp.page_id = random_num[i] / 10;
                page_in.push_back(temp);
                cout << "\t\t执行第" << i << "条指令，指令为：" << random_num[i] << endl;
                continue;
            }
            else
            {
                temp.page_id = random_num[i] / 10;
                page_in.push_back(temp);
                cout << "\t\t执行第" << i << "条指令,指令为：" << random_num[i] << endl;
                continue;
            }
        }
    }
    cout << "总共调页：" << merge_time << "次" << endl;
    cout << "缺页率为百分之" << merge_time / 0.5 << endl;
}

int OPT_sort(int j)    // 求最长未被使用的时间 ：返回page_in 的 id
{
    int max_opt = 0;
    for (int i = 0; i < 4;i++)
    {
        page_in[i].opt_time = 0;
        int temp = 1;
        int temp_j = j;
        while(temp_j<50)
        {
            if (page_in[i].page_id == random_num[temp_j] / 10)
            {
                page_in[i].opt_time = temp;
                if (page_in[i].opt_time > page_in[max_opt].opt_time)
                {
                    max_opt = i;
                }
                break;
            }

            else
            {
                temp++;
                temp_j++;
            }
        }
    }
    for (int i1 = 0; i1 < 4;i1++)
    {
        cout << page_in[i1].opt_time << endl;
    }
    for (int i = 0; i < page_in.size();i++)
    {
        if(page_in[i].opt_time==0)
        {
            return i;
        }
        else
        {
        }
    }
    return max_opt; 
} 
void OPT()
{
    page_in.erase(page_in.begin() + page_in.size() - 1);
    merge_time = 0;
    for (int i = 0; i < 50;i++)
    {
        page_print();
        if(in_memory(random_num[i]))
        {
            cout << "\t\t执行第" << i << "条指令，指令为：" << random_num[i] << endl;
            continue;
        }
        else
        {
            if(is_max())
            {
                merge_time++;
                page_in.erase(page_in.begin() + OPT_sort(i));
                temp.page_id = random_num[i] / 10;
                page_in.push_back(temp);
                cout<<"\t\t执行第" << i << "条指令，指令为：" << random_num[i] << endl;
                continue;
            }
            else
            {
                temp.page_id=random_num[i]/10;
                page_in.push_back(temp);
                cout<<"\t\t执行第"<<i<<"条指令,指令为："<<random_num[i]<<endl;
                continue;
            }
        }
    }
    cout << "总共调页：" << merge_time << "次" << endl;
    cout << "缺页率为百分之" << merge_time / 3.2 << endl;
}

void LRU_time()
{
    for (int i = 0; i < page_in.size();i++)
    {
        page_in[i].lru_time++;
    }
}
int max_lrutime()
{
    int max_id = 0;
    for (int i = 0; i < page_in.size();i++)
    {
        if(page_in[i].lru_time>page_in[max_id].lru_time)
        {
            max_id = i;
        }
        else
        {
            continue;
        }
    }
    return max_id;
}

void LRU()
{
    page_in.erase(page_in.begin() + page_in.size() - 1);
    merge_time = 0;
    for (int i = 0; i < 50;i++)
    {
        page_print();
        if(in_memory(random_num[i]))
        {
            LRU_time();
            for (int i1 = 0; i1 < page_in.size(); i1++)
            {
                if (page_in[i1].page_id == random_num[i] / 10)
                {
                    page_in[i1].lru_time = 0;
                    break;
                }
            }
            cout << "\t\t执行第" << i << "条指令,指令为：" << random_num[i] << endl;
            continue;
        }
        else
        {
            if (is_max())
            {
                merge_time++;
                LRU_time();
                page_in.erase(page_in.begin() + max_lrutime());
                temp.page_id = random_num[i] / 10;
                temp.lru_time = 0;
                page_in.push_back(temp);
                cout << "\t\t执行第" << i << "条指令,指令为：" << random_num[i] << endl;
                continue;
            }
            else
            {
                LRU_time();
                temp.page_id = random_num[i] / 10;
                temp.lru_time = 0;
                page_in.push_back(temp);
                cout << "\t\t执行第" << i << "条指令,指令为：" << random_num[i] << endl;
                continue;
            }
                }
            
        }
        cout << "总调页：" << merge_time << "次" << endl;
        cout << "缺页率为百分之" << merge_time / 3.2 << endl;
    }

void print_num()
{
    for (int i = 0; i < 50;i++)
        cout << random_num[i] << " ";
    cout << endl
         << endl;
    cout << "1、FIFO" << endl
         << "2、OPT" << endl
         << "3、LRU" << endl
         << "请输入要选择的算法：";
}

int main()
{
    int aa;
    random_();
    print_num();
    while(cin>>aa)
    {
        switch(aa)
        {
            case 0:
                return 0;
            case 1:
                FIFO();
                break;
            case 2:
                OPT();
                break;
            case 3:
                LRU();
                break;
            default:
                break;
        }
    }

    return 0;
}