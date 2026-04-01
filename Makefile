CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

OBJS = main.o

project4 : $(OBJS)
	$(CXX) $(CXXFLAGS) -o project4 $(OBJS)

main.o : main.cpp BinPacking.h Bin.h Item.h Permutation.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o project4