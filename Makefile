# compile all files
all: server.cpp client.cpp
	g++ -g -Wall client.cpp -o client
	g++ -g -Wall server.cpp -o server

# copile just the client or server
server: server.cpp
	g++ -g -Wall server.cpp -o server

client: client.cpp
	g++ -g -Wall client.cpp -o client

# clean build files
clean:
	rm client server
