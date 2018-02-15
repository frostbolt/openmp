ifdef SYSTEMROOT
   RM = del /Q
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
   endif
endif

FLAGS = -std=c++0x
#FLAGS = -std=c++11

default: all

all: clean main.o Matrix.o functions.o
	g++ $(FLAGS) main.o Matrix.o functions.o -o main

main.o: 
	g++ -c $(FLAGS) main.cpp -o main.o

functions.o: 
	g++ -c $(FLAGS) functions.cpp -o functions.o

Matrix.o:
	g++ -c $(FLAGS) Matrix.cpp -o Matrix.o

clean:
	$(RM) *.o all
