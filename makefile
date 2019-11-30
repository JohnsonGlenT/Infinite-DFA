CC = gcc -Wall

build: main.o dfa.o
	$(CC) -o isInfinite.out main.o dfa.o

main.o: main.c main.h
	$(CC) -c main.c

dfa.o: dfa.c dfa.h
	$(CC) -c dfa.c

clean:
	rm isInfinite.out *.o
