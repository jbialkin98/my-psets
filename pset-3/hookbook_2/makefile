CC = gcc
# Add back -Werror
CFLAGS = -std=c17 -Wall -pedantic -g

HookBook : hookbook.o pirate_list.o
	${CC} ${CFLAGS} -o $@ $^

clean : 
	rm -rf *.{o,a}
