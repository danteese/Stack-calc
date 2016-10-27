#Makefile practica stack en git
calc: main.o functions.o mathfn.o
	gcc -o calc main.o functions.o mathfn.o -lm

main.o: main.c
	gcc -c main.c

functions.o: functions.c
	gcc -c functions.c

mathfn.o: mathfn.c
	gcc -c mathfn.c

clean:
	rm *.o
