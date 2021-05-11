#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

#define N 50
int in = 0, out = 0;
int Buffer[N] = {0};
HANDLE dmutex,dempty,dfull;
DWORD WINAPI producer(void *p)
{
    while(1)
    {
        WaitForSingleObject(dempty, INFINITE);
        WaitForSingleObject(dmutex, INFINITE);
        Buffer[in] = 1;
        in = (in + 1) % 50;
        cout << "生产产品" <<in << endl;
        Sleep(500);
        ReleaseSemaphore(dmutex, 1, NULL);
        ReleaseSemaphore(dmutex, 1,NULL);

    }
    return 0;
}
DWORD WINAPI consumer(void *p)
{
    while(1)
    {
        WaitForSingleObject(dfull, INFINITE);
        WaitForSingleObject(dmutex, INFINITE);
        out = (out + 1) % N;
        cout << "消费商品" << out << endl;
        Sleep(500);
        ReleaseSemaphore(dmutex, 1, NULL);
        ReleaseSemaphore(dempty, 1, NULL);

    }
    return 0;
}
int main()
{
    dmutex = CreateSemaphore(NULL, 1, 1, NULL);
    dempty = CreateSemaphore(NULL, N, N, NULL);
    dfull = CreateSemaphore(NULL, 0, N, NULL);

    HANDLE hdproducer[5];
    HANDLE hdconsumer[5];
    for (int i = 0; i < 5;i++)
    {
        hdproducer[i] = CreateThread(NULL, 0, producer, NULL, 0, 0);
    }
    for (int i = 0; i < 5;i++)
    {
        hdconsumer[i] = CreateThread(NULL, 0, consumer, NULL, 0, 0);
    }
    WaitForMultipleObjects(5, hdproducer, TRUE, INFINITE);
    WaitForMultipleObjects(5, hdconsumer, TRUE, INFINITE);
    return 0;
}