/********************************************************
 * Function：Debug console
 * Compilation environment: GCC-4.1.2
 * The author：lishaozhe
 *******************************************************/
#include "debug_switch.h"
#include <getopt.h>

int get_parameter(int argc, char *argv[], struct message *msg);
void help();

int main(int argc, char *argv[])
{
	int qid;
	key_t key;
	struct message msg;
	msg.msg_pid = -1;
	memset(msg.msg_str.str_file, 0, FILE_SIZE);
	strcpy(msg.msg_str.str_file,"\0");
	if((key=ftok(KEY, 'a'))==-1)
	{
		perror("ftok");
		return OP_FAILED;
	}
	if((qid=msgget(key, IPC_CREAT|0666))==-1)
	{
		perror("msgget");
		return OP_FAILED ;
	}
 	/*Acquisition parameters function*/
	get_parameter(argc, argv, &msg);	
	
			
			
	if(msgsnd(qid, &msg, sizeof(msg.msg_str), 0)<0)
	{
		perror("msgsnd");
		help();
	}
	printf("Command effective!\n");	
		
	return OP_SUCCESS;
}

int get_parameter(int argc, char *argv[], struct message *msg)
{
	int opt;
	struct option long_options[] = {
	   {"pid",  required_argument, NULL, 'p'},
	   {"switch", required_argument, NULL, 's'},
	   {"file", required_argument, NULL, 'f'},
	};
	
	
	while((opt = getopt_long(argc, argv, "p:s:f:", long_options, NULL)) != -1)
	{
		switch (opt)
		{
			case 'p':
				msg->msg_pid=atoi(optarg);
			break;
			    
			case 's':
				strncpy(msg->msg_str.str_switch, optarg,sizeof(msg->msg_str.str_switch));
			break;
			    
			case 'f':
				strncpy(msg->msg_str.str_file, optarg,sizeof(msg->msg_str.str_file));
			break;
			
			default:
			    printf("You should look for help!\n ");
				help();
			break;            
		}
	}
	if(( -1 != msg->msg_pid) && ((strcmp(msg->msg_str.str_switch, "1") == 0 ) || 
				(strcmp(msg->msg_str.str_switch, "0") == 0)));

	else
	{
		help();
	}

	
	return OP_SUCCESS;

}


void help()
{
	printf("**********TURN ON DEBUG**********!\n");
	printf("*Please enter debug program pid(-p pid)!\n");
	printf("*please enter turn on debug(-s 1) or turn off debug(-s 0)!\n");
	printf("*please enter file path (-f path)\n");
	printf("*FORMAT# program -p pid -s 1 -f path \n");

	printf("**********TURN OFF DEBUG**********!\n");
	printf("*Please enter debug program pid(-p pid)!\n");
	printf("*please enter turn on debug(-s 1) or turn off debug(-s 0)!\n");
	printf("*FORMAT# program -p pid -s 0 \n");

	exit(0);
}
