# 0 - последовательное умножение матрицы
# 1 - обычное умножение матрицы openmp
# 2 - необычное умножение матрицы openmp
TYPE_MUL = -DMATRTIX_MUL=2

COMPILER = g++

FLAGS = -std=c++0x -Wall -Wextra -Wpedantic -fopenmp -O2
#FLAGS = -std=c++11

OS := $(shell uname)
ifeq ($(OS),Darwin)
	COMPILER = g++-8
endif

ifdef SYSTEMROOT
    RM = del /Q
else
    RM = rm -f
endif


default: all

all: clean main.o Matrix.o functions.o
	$(COMPILER) $(FLAGS) main.o functions.o Matrix.o -o main

main.o: 
	$(COMPILER) -c $(FLAGS) main.cpp -o main.o

functions.o: 
	$(COMPILER) -c $(FLAGS) functions.cpp -o functions.o

Matrix.o:
	$(COMPILER) -c $(FLAGS) $(TYPE_MUL) ../first/Matrix.cpp -o Matrix.o

clean:
	$(RM) *.o main all