EXEC = debug
objects = switch_control.o 
CFLAGS = -Wall -O2
CC = gcc 


$(EXEC) : $(objects)
	$(CC) -o $(EXEC) $(objects) $(CFLAGS)
Switch_Control.o :switch_control.c debug_switch.h 
	$(CC) -c switch_control.c $(CFLAGS)


.PHONY: clean 
clean : 
	rm -f $(objects) $(EXEC) 
