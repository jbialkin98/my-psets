CC = gcc
# Add back -Werror
CFLAGS = -std=c17 -Wall -pedantic -g

HookBook : hookbook.o pirate_list.o pirate.o
	${CC} ${CFLAGS} -o $@ $^

clean : 
	rm -rf *.{o,a}
