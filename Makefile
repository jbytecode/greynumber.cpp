CPP=g++
CFLAGS=-std=c++14
TESTINC=$(shell pkg-config --cflags catch2)
TESTLIB=$(shell pkg-config --libs catch2)

.PHONY: clean test

clean:
	rm -f greynumber
	rm -f test
	rm -f greynumber.dylib
	rm -f greynumber.o
	rm -f test.o

test.o: test.cpp
	$(CPP) -c $(CFLAGS) $(TESTINC) -o test.o test.cpp

test: greynumber.o test.o 
	$(CPP) $(CFLAGS) $(TESTINC) $(TESTLIB) -o test test.o greynumber.o
	./test --success

greynumber.o: greynumber.cpp
	$(CPP) $(CFLAGS) -c -o greynumber.o greynumber.cpp

lib: greynumber.o
	$(CPP) -dynamiclib -fPIC -O3 -o greynumber.dylib greynumber.o
