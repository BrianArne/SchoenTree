CXX = g++ -std=c++11

all: main

main: SchoenTree.o main.o
	$(CXX) -o main SchoenTree.o main.o

main.o: main.cpp
	$(CXX) -c main.cpp

SchoenTree.o: SchoenTree.cpp SchoenTree.h 
	$(CXX) -c SchoenTree.cpp
