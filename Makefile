server: server.o Utils.o Shinkansen.o Request.o Response.o Constants.o
		g++ -o build/server build/server.o build/Utils.o build/Shinkansen.o build/Request.o build/Response.o build/Constants.o --std=c++17

server.o: 
		g++ src/server.cpp -c -o build/server.o --std=c++17

Shinkansen.o:
		g++ src/Shinkansen.cpp -c -o build/Shinkansen.o --std=c++17

Utils.o:
		g++ src/Utils.cpp -c -o build/Utils.o --std=c++17


Request.o:
		g++ src/Request.cpp -c -o build/Request.o --std=c++17

Response.o:
		g++ src/Response.cpp -c -o build/Response.o --std=c++17

Constants.o:
		g++ src/Constants.cpp -c -o build/Constants.o --std=c++17







comp:
		g++ src/playground.cpp -o build/play.o --std=c++17

runp:
		./build/play.o

clean: 
		rm ./build/*

run:
		./build/server











