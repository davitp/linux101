#include <cstdio>
#include <cstring>	
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>	
#include <cerrno>
#include <iostream>

int main(int argc , char *argv[])
{
    	// create a socket of (AF_INET -> Internet Protocol, SOCK_STREAM -> TCP Transport)
    	int serverSocket = socket(AF_INET , SOCK_STREAM , 0);

    	// make sure socket was created
	if (serverSocket == -1)
	{
        	std::cerr << "Error while creating a socket" << std::endl;
		exit(errno);
	}

    	std::cout << "Created a socket file descriptor: " << serverSocket << std::endl;

    	// create a socket address descriptor
	struct sockaddr_in server;
	
    	// lestening to Ineternet Protocol connections
    	server.sin_family = AF_INET;

    	// accept from any address
	server.sin_addr.s_addr = htonl( INADDR_ANY );

	// listen on given port
	server.sin_port = htons( 9988 );
	
    	// bind socket to given address 
    	int bindResult = bind(serverSocket,  (struct sockaddr*) &server , sizeof(server));

    	// make sure bind was successful
	if(bindResult == -1)
	{
        	std::cerr << "Error while binding a socket" << std::endl;
		exit(errno);
	}

    	std::cout << "Bind operation was successful..." << std::endl;

    	// start listening on the bound socket (maximum 1024 connections)
    	int listenResult = listen(serverSocket , 1024);

    	// make sure listen is successful
    	if(listenResult == -1)
    	{
        	std::cerr << "Cannot start listening on a given socket" << std::endl;
        	exit(errno);
    	}

    	std::cout << "Waiting for connections..." << std::endl;

    	// doing this 10 times
    	while(true)
    	{
        	// a client socket address
        	sockaddr_in clientAddress;

		unsigned int addressSize = 0;

	        // accept a connection
        	int clientSocket = accept(serverSocket, (struct sockaddr*) &clientAddress, &addressSize);

        	// make sure everything is alright
        	if(clientSocket == -1)
        	{
            		std::cerr << "Something went wrong while accepting a connection" << std::endl;
            		exit(errno);
        	}

        	std::cout << "New connection from " << inet_ntoa(clientAddress.sin_addr) << std::endl;

        	// prepare a buffer to read a message from client	
        	char clientMessage[2001];

        	// try read from client once
        	int readSize = recv(clientSocket, clientMessage , 2000 , 0);

        	// error while reading
        	if(readSize == -1)
        	{
            		std::cerr << "Something went wrong while reading from clinet...";
            		close(clientSocket);
            		continue;
        	}

        	if(readSize > 0)
        	{
            		clientMessage[readSize] = '\0';
            		std::cout << "Got message: " << clientMessage << std::endl;
        	}

        	close(clientSocket);
    	}

	close(serverSocket);
	
	return 0;
}
