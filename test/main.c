/********************************************************
 * Function：test!
 * Compilation environment: GCC-4.1.2
 * The author：lishaozhe
 *******************************************************/

#include "debug_switch.h"
#include "debug.h"
int g_iDebug ;
int main()
{
	int old_bug = g_iDebug;
	DEBUG("g_iDebug = %d\n", g_iDebug);
	init_debug_notify();
	DEBUG("*******test*********\n");
	while(1)
	{
		
		//if(old_bug != g_iDebug)
		{	
			DEBUG("*******main*********\n");
			DEBUG("g_iDebug = %d\n",g_iDebug);
			DEBUG("old_bug = %d\n",old_bug);
			old_bug = g_iDebug;
			DEBUG("*******main*********\n");
		}
	
		sleep(1);

	}

	return 0;


}
