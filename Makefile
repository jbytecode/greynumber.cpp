CPP=g++
CFLAGS=-std=c++11
GTESTINC=$(shell pkg-config --cflags gtest)
GTESTLIB=$(shell pkg-config --libs gtest)

.PHONY: clean test

clean:
	rm -f greynumber
	rm -f test
	rm -f greynumber.dylib
	rm -f greynumber.o
	rm -f test.o

test.o: test.cpp
	$(CPP) -c $(CFLAGS) $(GTESTINC) -o test.o test.cpp

test: greynumber.o test.o 
	$(CPP) $(CFLAGS) $(GTESTINC) $(GTESTLIB) -o test test.o greynumber.o
	./test

greynumber.o: greynumber.cpp
	$(CPP) $(CFLAGS) -c -o greynumber.o greynumber.cpp

lib: greynumber.o
	$(CPP) -dynamiclib -fPIC -O3 -o greynumber.dylib greynumber.o
