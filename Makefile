lp2: lp2.o
	g++ lp2.o -o lp2

lp2.o: lpProblem2.cpp
	g++ -c lpProblem2.cpp -o lp2.o

clean:
	rm -f lp2 lp2.o
