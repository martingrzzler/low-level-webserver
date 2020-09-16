server: server.o Utils.o Shinkansen.o Request.o Response.o
		g++ -o build/server build/server.o build/Utils.o build/Shinkansen.o build/Request.o build/Response.o

server.o: 
		g++ src/server.cpp -c -o build/server.o

Shinkansen.o:
	g++ src/Shinkansen.cpp -c -o build/Shinkansen.o

Utils.o:
		g++ src/Utils.cpp -c -o build/Utils.o


Request.o:
		g++ src/Request.cpp -c -o build/Request.o

Response.o:
		g++ src/Response.cpp -c -o build/Response.o

comp:
		g++ src/playground.cpp -o build/play.o --std=c++17

runp:
		./build/play.o

clean: 
		rm ./build/*

run:
		./build/server











