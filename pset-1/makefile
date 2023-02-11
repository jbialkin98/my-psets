# makefile
# Josh Bialkin
# CPSC 223 pset-2
# 2/11/23
# Allows command "make" to be used, bunding files together
# 	so the program can run

CC =     gcc
CFLAGS = -std=c17 -Wall -pedantic -g

.PHONY: clean

Life: main.o life.o
	${CC} ${CFLAGS}	-o $@ $^

clean:
	rm -f *.o
	rm -f Life