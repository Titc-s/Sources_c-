#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

const int n = 10;
int i = 0,j = 0;
int itemp = 0, itemc=0;
int buffer[n]={0};

HANDLE empty, full, mutex;
HANDLE pThread, cThread;

DWORD WINAPI producer(LPVOID lp);
DWORD WINAPI consumer(LPVOID lc);

int main()
{
	empty = CreateSemaphore(NULL, n, n, NULL);		//缓冲区空闲位置的个数
	full = CreateSemaphore(NULL,0,n,NULL);			//缓冲区不空闲位置的个数
	mutex = CreateSemaphore(NULL,1,1,NULL);			//缓冲区互斥量
	
	cThread = CreateThread(NULL,0,consumer,NULL,0,NULL);		//创建消费者线程
	pThread = CreateThread(NULL,0,producer,NULL,0,NULL);		//创建生产者线程
	
	WaitForSingleObject(pThread,INFINITE);
	WaitForSingleObject(cThread,INFINITE);
	
	
	CloseHandle(empty);
	CloseHandle(full);
	CloseHandle(mutex);
	CloseHandle(pThread);
	CloseHandle(cThread);
	
	return 0;
}

DWORD WINAPI producer(LPVOID lp)
{
	for(int x=0;x<20;x++)
	//while(1)
	{
		WaitForSingleObject(empty, INFINITE);		//信号量为unsigned 即阻塞
		WaitForSingleObject(mutex, INFINITE);		//信号量为signed 即唤醒

		srand(time(NULL));				//1秒内随机时间生产产品
		Sleep(rand()%1000);

		cout<<"produce then put it in: (position "<<i<<')'<<endl;
		buffer[i]=++itemp; i=(i+1)%n;
		for(int k=0;k<n;k++) 
			cout<<buffer[k]<<' ';
		cout<<endl;
		
		ReleaseSemaphore(mutex,1,NULL);
		ReleaseSemaphore(full,1,NULL);
	}
	return 0;
}

DWORD WINAPI consumer(LPVOID lc)
{
	for(int x=0;x<20;x++)
	//while(1)
	{
		WaitForSingleObject(full,INFINITE);
		WaitForSingleObject(mutex,INFINITE);

		srand(time(NULL));
		Sleep(rand()%1000);

		cout<<"consume then get it out: (position "<<j<<')'<<endl;
		itemc=buffer[j];
		buffer[j]=0;
		j=(j+1)%n;
		for(int k=0;k<n;k++)
			cout<<buffer[k]<<' ';
		cout<<endl;
		
		ReleaseSemaphore(mutex,1,NULL);
		ReleaseSemaphore(empty,1,NULL);
	}
	return 0;
}
