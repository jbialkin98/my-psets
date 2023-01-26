# C compiler and flags
CC     = gcc
CFLAGS = -std=c17 -Wall -pedantic -g

# Targets

# TODO: Dummy target. Edit so it satisfies the requirements.
# Hello: 
# 	touch $@

Hello: main.o
	${CC} ${CFLAGS} -o $@ $^

clean:
	rm -f *.o
	rm -f Hello