int	pthread_create(pthread_t *tid, const pthread_attr_t *tattr, void*(*start_routine)(void *), void *arg); 

#include <pthread.h>

pthread_attr_t ()tattr;
pthread_t tid;
extern void *start_routine(void *arg);
void *arg;
int ret; 

/* デフォルト動作 */
ret = pthread_create(&tid, NULL, start_routine, arg);

