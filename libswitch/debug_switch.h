/********************************************************
 * Function：Debug redirection header files
 * Compilation environment: GCC-4.1.2
 * The author：lishaozhe
 *******************************************************/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>
#define DEBUGSWITCH_H

#ifdef OP_SUCCESS
#else
#define OP_SUCCESS 0
#define OP_FAILED -1
#endif

#define KEY  "/root"

#define BUFFER_SIZE 10
#define FILE_SIZE 50

struct str_str
{
	char str_file[FILE_SIZE]; /*Access debug file path*/
	char str_switch[BUFFER_SIZE];/*Access debug command*/
};
struct message
{
	long msg_pid;/*Access process pid*/
	struct str_str msg_str;
};


int init_debug_notify();

int monitor_debug(void *qqid);



