all : test
	./test

test : maybe.hpp test.cpp
	${CXX} -std=c++11 -I. -o test test.cpp

clean :
	rm test
