all: compile link clear run

compile:
	g++ -c *.cpp src/*.cpp src/containers/*.cpp

link:
	g++ *.o -o main -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

clear:
	rm -rf *.o

run:
	./main