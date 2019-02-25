linsolve: main.o linsolve.o gendata.o checkresult.o
	gcc -o  linsolve main.o linsolve.o gendata.o checkresult.o -lm
main.o: main.c
	gcc -c main.c
linsolve.o: linsolve.c
	gcc -c linsolve.c
gendata.o: gendata.c
	gcc -c gendata.c
checkresult.o: checkresult.c
	gcc -c checkresult.c

clean:
	rm *.o linsolve