#Makefile practica stack en git
stack: main.o functions.o mathfn.o
	gcc -o stack main.o functions.o

main.o: main.c
	gcc -c main.c

functions.o: functions.c
	gcc -c functions.c

mathfn.o: mathfn.c
	gcc -c mathfn.c

clean:
	rm *.o
