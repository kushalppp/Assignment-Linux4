#include<stdio.h>
#include<pthread.h>

int buffer[16];
pthread_mutex_t mutex;

void* producer(void* p)
{
pthread_mutex_lock(&mutex);
int i;
printf("enter a no.//From producer side//\n");
for(i=0;i<16;i++)
{
scanf("%d\n",&buffer[i]);
}
pthread_mutex_unlock(&mutex);
}

void* consumer(void* q)
{
pthread_mutex_lock(&mutex);
int i;
printf("//From consumer side//\n");
for(i=0;i<16;i++)
{
printf(" -%d- ",buffer[i]);
}
pthread_mutex_unlock(&mutex);
}

main()
{
pthread_mutex_init(&mutex,NULL);
pthread_t t1,t2;
int ret,ret1;
ret=pthread_create(&t1,NULL,producer,NULL);
ret1=pthread_create(&t2,NULL,consumer,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
if(ret==ret1==0)
{
printf(" Thread is created\n");
}
pthread_mutex_destroy(&mutex);
}


Output:-
enter a no.//From producer side//
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
//From consumer side//
 -1-  -2-  -3-  -4-  -5-  -6-  -7-  -8-  -9-  -10-  -11-  -12-  -13-  -14-  -15-  -16- 