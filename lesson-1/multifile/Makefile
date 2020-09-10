all: main

main: main.o message.o
	g++ main.o message.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

message.o: message.cpp
	g++ -c message.cpp -o message.o

clean:
	rm *.o main
