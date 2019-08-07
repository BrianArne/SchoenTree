CXX = g++

all: SchoenTree

SchoenTree: SchoenTree.o SchoenNode.o
	$(CXX) -o SchoenTree SchoenTree.o

SchoenTree.o: SchoenTree.cpp SchoenTree.h SchoenNode.h
	$(CXX) -c SchoenTree.cpp

SchoenNode.o: SchoenNode.cpp SchoenNode.h
	$(CXX) -c SchoenNode.cpp

