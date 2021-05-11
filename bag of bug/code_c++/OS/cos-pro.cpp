#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<process.h>
using namespace std;

#define N 10
int in = 0,out=0;
int buffer[N] = {0}; // 设置缓冲区
HANDLE mutex, dempty, dfull;
//句柄（Handle）是一个是用来标识对象或者项目的标识符，可以用来描述窗体、文件等
// mutex:互斥量
//dempty: 空闲缓冲区数量
//dfull：可供消耗的资源数量

void show()
{
for (int i = 0; i < 10;i++)
  {
    if(buffer[i]==1)
        cout << i+1 << " ";
     else
         cout << "0 ";
  } 
   cout << endl;
}//输出缓冲池情况

DWORD WINAPI producer(void *p){
    //DWORD 是双字节数据类型，
    //WINAPI _stdall 可实现自动清栈 为c/c++ 函数调用方法
    while(1)
    {
        WaitForSingleObject(dempty,INFINITE); 
         // WaitForSingleObject函数用来检测hHandle事件的信号状态
         //在某一线程中调用该函数时，线程暂时挂起，当等待仍在挂起状态时，句柄被关闭，那么函数行为是未定义的
        WaitForSingleObject(mutex, INFINITE);
        buffer[in] = 1;
        cout << "生产者生产了了一个产品，缓冲区状态：";
        show();
        in = (in + 1) % N;
        Sleep(999);// 线程休眠
        ReleaseSemaphore(mutex, 1, NULL);
        //ReleaseSemaphore 函数可以按指定数量增加指定信号量对象的计数。
        ReleaseSemaphore(dfull, 1, NULL);
    }
    return 0;
}

DWORD WINAPI consumer(void *p){
    while(1){
        WaitForSingleObject(dfull, INFINITE);
        WaitForSingleObject(mutex, INFINITE);
        buffer[out] = 0;
        cout << "消费者消费了一个产品，缓冲区状态：";
        show();
        in = (in + 1) % N;
        Sleep(999);
        ReleaseSemaphore(mutex, 1, NULL);
        ReleaseSemaphore(dempty, 1, NULL);

    }
    return 0;
    }


int main()
{
    HANDLE consumers[1],producers[2];
    mutex = CreateSemaphore(NULL, 1, 1, NULL);
    //CreateSemaphore 创建或打开命名或未命名的信号量对象。
    dempty = CreateSemaphore(NULL, N, N, NULL);
    dfull = CreateSemaphore(NULL, 0, N, NULL);
    for (int i = 0; i < 2; i++){
        producers[i] = CreateThread(NULL, 0, producer, NULL, 0, 0);
        //CreateThread 创建线程
        if (producers[i] ==NULL)
            return -1;
    }
    for (int i = 0; i < 1;i++){
        consumers[i] = CreateThread(NULL, 0, consumer, NULL, 0, 0);
        if(consumers[i]==NULL)
            return -1;
    }
    WaitForMultipleObjects(2, producers, TRUE, INFINITE);
    WaitForMultipleObjects(1, consumers, TRUE, INFINITE);
    /*
    DWORD WaitForMultipleObject(DWORD dwCount , CONST HANDLE* phObject, BOOL fWaitAll, DWORD dwMillisecinds);
dwCount参数 用于指明想要让函数查看的内核对象的数量。这个值必须在1与MAXIMUM_WAIT_OBJECTS(在Windows头文件中定义为64之间.
phObjects参数 是指向内核对象句柄的数组的指针。可以以两种不同的方式来使用WaitForMultipleObjects函数。一种方式是让线程进入等待状态，
直到指定内核对象中的任何一个变为已通知状态。另一种方式是让线程进入等待状态，直到所有指定的内核对象都变为已通知状态。
fWaitAll参数 告诉该函数，你想要让它使用何种方式。如果为该参数传递TRUE，那么在所有对象变为已通知状态之前，该函数将不允许调用线程运行。
dwMil liseconds参数 该参数的作用与它在WaitForSingleObject中的作用完全相同。如果在等待的时候规定的时间到了，那么该函数无论如何都会返回。
同样，通常为该参数传递INFINITE，但是在编写代码时应该小心，以避免出现死锁情况。
    */
    return 0;
}