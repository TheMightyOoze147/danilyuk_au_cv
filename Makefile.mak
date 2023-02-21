output: lab1.o mylib.o
	g++ lab1.o mylib.o -o lab1

lab1.o: lab1.cpp
	g++ -c lab1.cpp

mylib.o: mylib.cpp mylib.h
	g++ -c mylib.cpp

clean:
	rm *.o output