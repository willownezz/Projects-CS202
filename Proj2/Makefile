

.cpp:
		g++ -o $* $*.cpp -std=c++11



poly_class:	Polynomial.o poly_class.o
		g++ -o $@ $@.o Polynomial.o  -std+c++11


%.o: %.cpp Polynomial.h
		g++ -c
