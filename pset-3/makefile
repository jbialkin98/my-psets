CC = gcc
CFLAGS = -std=c17 -Wall -pedantic -g

HookBook : hookbook.o pirate_list.o
	${CC} ${CFLAGS} -o $@ $^

clean : 
	rm -rf *.{o,a}
