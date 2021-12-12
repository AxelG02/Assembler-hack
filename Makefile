main: main.o symboltable.o translate.o utils.o
	gcc -o main.out main.o symboltable.o translate.o utils.o

main.o: main.c symboltable.h translate.h
	gcc -c main.c

symboltable.o: symboltable.c symboltable.h
	gcc -c symboltable.c

translate.o: translate.c translate.h
	gcc -c translate.c

utils.o: utils.c utils.h
	gcc -c utils.c

clean:
	rm *.o main.out