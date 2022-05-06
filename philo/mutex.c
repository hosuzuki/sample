#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_CNT 10000

int	global_cnt;
pthread_mutex_t mutex;

void thread(void)
{
	int i = 0, cnt = 0;

	printf("thread[%lu] start\n", pthread_self());
	/* counter increment */
	for(i = 0; i < MAX_CNT; i++)
	{
		pthread_mutex_lock(&mutex);
		cnt = global_cnt;
		cnt++;
		global_cnt = cnt;
		pthread_mutex_unlock(&mutex);
	}
	printf("thread[%lu] end\n", pthread_self());
	pthread_exit(0);
}

int main(void)
{
	int i = 0;
	pthread_t thread_id[MAX_THREADS];
	void *thread_return;

	printf("sample program(%s) start\n", __FILE__);
	pthread_mutex_init(&mutex, NULL);
	/* create new threads */
	for(i = 0; i < MAX_THREADS; i++)
	{
		if(pthread_create(&thread_id[i], NULL, (void *)thread, NULL) < 0)
		{
			perror("pthread_create error");
			exit(1);
		}        
	}

	/* wait for the end of threads */
	for(i = 0; i < MAX_THREADS; i++)
	{
		if(pthread_join(thread_id[i], &thread_return) < 0)
		{
			perror("pthread_join error");
			exit(1);
		}        
	}
	printf("global_cnt = %d\n", global_cnt);
	return 0;
}
