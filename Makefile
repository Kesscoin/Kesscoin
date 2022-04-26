all:
	mkdir -p bin
	g++ src/*.cpp -I include -o bin/kesscoin
