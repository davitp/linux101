#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <arpa/inet.h>


int main(){


	// a structure to fill the server address
	struct sockaddr_in serverAddress;

	// create an internet socket
	int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	// fill server address with 0s
	memset(&serverAddress, '\0', sizeof(serverAddress));
	
	// fill the server ip and port address
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(9988);

	// connect socket to given address
	int connected = connect(clientSocket, ( struct sockaddr* ) &serverAddress, sizeof(serverAddress));

	if(connected == -1){
		exit(errno);
	}
	
	char input[2000];
	std::cout << "Successfuly connected to server Enter message to send:";
	std::cin >> input;	

	int sent = send(clientSocket, input, strlen(input) + 1, 0);

	if(sent == -1){
		exit(errno);
	}

	close(clientSocket);


	return 0;
}
