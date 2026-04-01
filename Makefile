CXX = g++
CXXFLAGS = -std=c++17 -Wall

OBJS = main.o

binpacking : $(OBJS)
	$(CXX) $(CXXFLAGS) -o project4 $(OBJS)

main.o : main.cpp BinPacking.h Bin.h Item.h Permutation.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o project4