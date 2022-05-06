#include <pthread.h>

pthread_mutex_t g_count_mutex;
long long g_count;

void	increment_count()
{
	pthread_mutex_lock(&g_count_mutex);
	g_count = g_count + 1;
	pthread_mutex_unlock(&g_count_mutex);
}

long long	get_count()
{
	long long	c;

	pthread_mutex_lock(&g_count_mutex);
	c = g_count;
	pthread_mutex_unlock(&g_count_mutex);
	return (c);
}

int main()
{
	
