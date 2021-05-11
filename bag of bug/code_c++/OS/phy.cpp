#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5
// 信号量使用参数
sem_t chopsticks[N];
sem_t r;
int philosophers[N] = {0, 1, 2, 3, 4};
// swap指令需要参数
int islocked[N] = {0};
// 互斥锁 使用参数
pthread_mutex_t chops[N];


//延迟函数
void delay(int len){
    int i = rand() % len;
    int x;
    while(i>0){
        x = rand() % len;
        while(x>0){
            x--;
        }
        i--;
    }
    
}
// 交换函数
void xchg(int *x,int *y){
    __asm__("xchgl %0,%1":"=r"(*x):"m"(*y));
}

void philosopher(void *arg){
    int i = *(int *)arg;
    int left = i;
    int right = (i + 1) % N;
    int leftkey, rightkey;
    while(1){
        leftkey = 1;
        rightkey = 1;
        printf("哲学家%d正在思考问题\n", i);
        delay(50000);
        printf("哲学家%d饿了\n", 1);
        sem_wait(&r);

        //sem_wait(&chopsticks[left]);
        //pthread_mutex_lock(&chopsticks[left]);
        do{
            xchg(&leftkey, &islocked[left]);
        } while (leftkey);
        printf("哲学家%d拿起了%d号筷子，现在只有一只筷子，不能进餐\n", i, left);
         //sem_wait(&chopsticks[right]);
        //pthread_mutex_lock(&chopsticks[right]);
        do{
               xchg(&rightkey, &islocked[right]);
        } while (rightkey);
        printf("哲学家%d拿起了%d号筷子，现在有两只筷子，开始进餐\n", i, right);

    }
}
