#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex;
char str1[51]="A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
char str[51]="a b c d e f g h i j k l m n o p q r s t u v w x y z";

void * pattern(void* p)
{
pthread_mutex_lock(&mutex);
FILE *fp;
fp=fopen("temp.text","a");
if(fp==NULL)
{
printf(" \n Can not open file");
exit(1);
}
fputs(str1,fp);
fclose(fp);
pthread_mutex_unlock(&mutex);
}

void *pattern2(void *q)
{
pthread_mutex_lock(&mutex);
FILE *fp;
fp=fopen("temp.text","a");
if(fp==NULL)
{
printf(" \n Can not open file");
exit(1);
}
fputs(str,fp);
fclose(fp);
pthread_mutex_unlock(&mutex);
}
 
main()
{
pthread_mutex_init(&mutex,NULL);
pthread_t t1 ,t2;
int ret1,ret2;
ret1=pthread_create(&t2,NULL,pattern2,NULL);
ret2=pthread_create(&t1,NULL,pattern,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
if(ret1==ret2==0)
{
printf("Thread is created");
}
pthread_mutex_destroy(&mutex);
}
