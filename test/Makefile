EXEC = libtest
SOURCE = ./main.c
CFLAGS =  -L ../libswitch/ -lswitch
CFLAGS += -Wall -O2
CFLAGS += -lpthread
CC = gcc

all: subsystem libtest

subsystem: 
	make -C ../libswitch 

libtest : main.c  debug_switch.h
	$(CC) -o $(EXEC) $(SOURCE)  $(CFLAGS)

clean :
	make clean -C ../libswitch
	rm -rf  $(EXEC)


