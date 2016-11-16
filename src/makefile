all: prog clean

debug.o: debug.cpp defines.h
	g++ -c -Wall debug.cpp

utils.o: utils.cpp defines.h
	g++ -c -Wall utils.cpp

main.o: main.cpp defines.h
	g++ -c -Wall main.cpp

prog: utils.o main.o debug.o
	g++ -g -Wall main.o utils.o debug.o -o simulacao

clean:
	rm -f *.o
