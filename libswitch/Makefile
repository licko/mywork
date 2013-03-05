LIB = libswitch.a
objects = init_debug_notify.o monitor_debug.o
CFLAGS = -Wall -O2
CC = gcc 

libswitch : $(objects) 
	ar -rc $(LIB) $(objects) 
init_debug_notify.o :  init_debug_notify.c debug_switch.h debug.h
	$(CC) -c init_debug_notify.c  $(CFLAGS) -lpthread
monitor_debug.o:  monitor_debug.c debug_switch.h debug.h
	$(CC) -c monitor_debug.c $(CFLAGS)

.PHONY: clean 
clean : 
	rm -f $(objects) $(LIB) 


