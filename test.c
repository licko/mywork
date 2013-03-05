#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
struct data
{
	unsigned  char res1:4;
	unsigned  char doff :4;
};
int main(int argc, char *argv[])
{
	printf("cplumns: %s\n",getenv("CPLUMNS"));	
	printf("HOME: %s\n",getenv("HOME"));	
	printf("datemsk: %s\n",getenv("DATEMSK"));	
	printf("lang: %s\n",getenv("LANG"));	
	printf("lc_all: %s\n",getenv("LC_ALL"));	
	printf("logname: %s\n",getenv("LOGNAME"));	
	printf("tz: %s\n",getenv("TZ"));	
	printf("shell: %s\n",getenv("SHELL"));	
	return 0;
}
