output: main.o
	g++ main.o -Wall -o output
	./output

Alg.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o output
	rm -f *.o alg
	rm -f *.txt datos
	rm -f *.txt semiorden


	
	