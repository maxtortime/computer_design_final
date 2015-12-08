main: main.o card.o
	gcc -o main main.o card.o

main.o: card.h main.c
	gcc -c main.c

card.o: card.h card.c
	gcc -c card.c
