CPP=clang++

.PHONY: clean test

clean:
	rm -f greynumber
	rm -f test
	rm -f greynumber.dylib
	rm -f greynumber.o
	rm -f test.o

test: greynumber.o 
	$(CPP) -c -o test.o test.cpp
	$(CPP) -o test test.o greynumber.o
	./test

greynumber.o: greynumber.cpp
	$(CPP) -c -o greynumber.o greynumber.cpp

lib: greynumber.o
	$(CPP) -dynamiclib -fPIC -O3 -o greynumber.dylib greynumber.o