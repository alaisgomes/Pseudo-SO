all: prog clean

utils.o: utils.cpp defines.h
	g++ -c -Wall utils.cpp

main.o: main.cpp defines.h
	g++ -c -Wall main.cpp

prog: utils.o main.o
	g++ -g -Wall main.o utils.o -o simulacao

clean:
	rm -f *.o
