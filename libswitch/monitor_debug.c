/********************************************************
 * Function：Monitor debug state function
 * Compilation environment: GCC-4.1.2
 * The author：lishaozhe
 *******************************************************/

#include "debug.h"
#include "debug_switch.h"
int monitor_debug(void *qqid)
{
	int qid = (int) qqid;
	struct message msg;
	/*cmd is operating command
	fd is memory debugging information file*/
	int cmd, fd = -1;
	int old_cmd = 0;
	/*Storage standard output file descriptors*/
	int fd_stdout;
	/*Storage standard error file descriptors*/
	int fd_stderr;
	/*Get process number*/
	pid_t pid;	
	pid = getpid();
	printf("pid = %d\n",pid);
	
	
	/*Empty storage area*/	
	memset(msg.msg_str.str_switch, 0, BUFFER_SIZE);
	memset(msg.msg_str.str_file, 0, FILE_SIZE);

	if((fd_stdout = dup(STDOUT_FILENO)) < 0)
	{
		DEBUG("PID = %d :fd_stdout dup", pid);
	}

	if((fd_stderr = dup(STDERR_FILENO)) < 0)
	{
		DEBUG("PID = %d :fd_stderr dup", pid);
	}

	while(1)
	{	
		int nu;	
		
		if(msgrcv(qid, &msg, sizeof(msg.msg_str), pid, 0) < 0)
		{
			
			int q_id;
			key_t key;
			DEBUG("PID = %d :msgrcv", pid);
			if(errno == EIDRM)
			{	if((key=ftok(KEY, 'a'))==-1)
				{
					DEBUG("PID = %d :fork", pid);
				}
				if((q_id=msgget(key, IPC_CREAT|0666))==-1)
				{
					DEBUG("PID = %d :msgget", pid);
				}
				qid = q_id;
			}			
		}
		else
		{
			cmd = atoi(msg.msg_str.str_switch);
			if(cmd == 1) 
			{	
				
				g_iDebug = 1;
				/*Standard output redirection to the specified file*/
				if(strcmp(msg.msg_str.str_file, "\0") != 0) 
				{	
					
					nu = 0;
					while(((fd = open(msg.msg_str.str_file, O_RDWR|O_CREAT|O_APPEND)) < 0) && nu < 5)
					{
						DEBUG("PID = %d :flie open", pid);
						nu++;
					}
					
				 	if((dup2(fd, STDOUT_FILENO)) < 0)
					{
						DEBUG("PID = %d :fd to STDOUT_FILENO dup2", pid);
					}
					if((dup2(fd, STDERR_FILENO)) < 0)
					{
						DEBUG("PID = %d :fd to STDOUT_FILENO dup2", pid);
					}
					

					setbuf(stdout,NULL);
					setbuf(stderr,NULL);
				}
				else
				{
					
					close(STDOUT_FILENO);
					close(STDERR_FILENO);
					nu = 0;
					while((NULL == freopen("/dev/tty","w",stdout)) && nu < 5)
					{
						nu++;
						DEBUG("PID = %d :freopen stdout\n", pid);
					}
					nu = 0;	
					while((NULL == freopen("/dev/tty","w",stderr)) && nu < 5)
					{
						nu++;
						DEBUG("PID = %d :freopen stderr\n", pid);
					}
					
				}
				DEBUG("*****************PID = %d debug*********************\n", pid);
				old_cmd = cmd;
				
			}
			if((cmd == 0) && (cmd != old_cmd))
			{	
				
				g_iDebug = 0;
				/*Recovery standard output*/
				
				close(fd);				
				old_cmd = cmd;
				if(msgctl(qid,IPC_RMID,NULL) < 0)
				{
					DEBUG("PID = %d :msgctl", pid);				
				}
			}
		}
	}
	return OP_SUCCESS;
}
