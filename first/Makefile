default: all

all: clean main.o Matrix.o functions.o
		g++ -std=c++11 main.o Matrix.o functions.o -o main

main.o: 
		g++ -c -std=c++11 main.cpp -o main.o

functions.o: 
		g++ -c -std=c++11 functions.cpp -o functions.o

Matrix.o:
		g++ -c -std=c++11 Matrix.cpp -o Matrix.o

clean:
		rm -rf *.o main