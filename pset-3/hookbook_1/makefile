CC = gcc
CFLAGS = -std=c17 -Wall -Werror -pedantic -g

HookBook : hookbook.o pirate_list.o pirate.o
	${CC} ${CFLAGS} -o $@ $^

clean : 
	rm -rf *.{o,a}
