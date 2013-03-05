/*
 *	debug.h
 *	chp[2011-11-23]
 *
 */
 
#ifndef _CHP_DEBUG_H_
#define _CHP_DEBUG_H_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <iconv.h>

//#include "DACommon.h"

#define SIG_ZERO		0

#define DELETE_FILE(File) \
{ \
	char szCmd[256]={0}; \
	snprintf(szCmd, sizeof(szCmd)-1, "rm -rf \"%s\"", File); \
	system(szCmd); \
}

extern int g_iDebug;

static inline void DEBUG(char *str, ...)
{
#ifdef CHP_DEBUG
	/*va_list va;
	char szBuff[256];
	
	memset(szBuff, 0, sizeof(szBuff));
	va_start (va, str);
	vsnprintf(szBuff, sizeof(szBuff)-1, str, va);
	va_end(va);
	printf("%s", szBuff);*/
#endif

//#ifdef CHP_DEBUG_D
	if(g_iDebug > 0)
	{
		va_list va;
		char szBuff[256];
			
		memset(szBuff, 0, sizeof(szBuff));
		va_start (va, str);
		vsnprintf(szBuff, sizeof(szBuff)-1, str, va);
		va_end(va);
		printf("%s", szBuff);
	}
//#endif
    return ;
}


#endif



