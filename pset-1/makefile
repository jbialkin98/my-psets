CC =     gcc
CFLAGS = -std=c17 -Wall -pedantic -g

.PHONY: clean

Life: main.o life.o life.h
	${CC} ${CFLAGS}	-o $@ $^

clean:
	rm -f *.o
	rm -f Life