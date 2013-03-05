
/********************************************************
 * Function：Initialization debug
 * Compilation environment: GCC-4.1.2
 * The author：lishaozhe
 *******************************************************/
#include "debug.h"
#include "debug_switch.h"
int init_debug_notify()
{
	int qid;
	key_t key;
	pthread_t tid;
	pid_t pid;
	pid = getpid();
	if((key=ftok(KEY, 'a'))==-1)
	{
		printf("PID = %d :fork", pid);
		return OP_FAILED;
	}

	if((qid=msgget(key, IPC_CREAT|0666))==-1)
	{
		printf("PID = %d :msgget", pid);
		return OP_FAILED;
	}

	int result = pthread_create(&tid, NULL, (void*)monitor_debug, (void *)qid);
    if(result != 0)
	{
    	DEBUG("PID = %dpthread_create", pid);
    	return OP_FAILED;
    }		
	return OP_SUCCESS;
}

