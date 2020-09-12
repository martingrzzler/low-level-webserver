server: server.o utils.o 
		g++ -o build/server build/server.o build/Utils.o

server.o: 
		g++ src/server.cpp -c -o build/server.o
utils.o:
		g++ src/Utils.cpp -c -o build/Utils.o









play:
		g++ src/playground.cpp -o build/play.o --std=c++17

clean: 
		rm ./build/*

run:
		./build/server











