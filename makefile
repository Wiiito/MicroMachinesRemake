all: compile link clear run

compile:
	g++ -c *.cpp src/*.cpp src/containers/*.cpp -ISFML/include

link:
	g++ *.o -o main -LSFML/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

clear:
	rm -rf *.o

run:
	./main.exe