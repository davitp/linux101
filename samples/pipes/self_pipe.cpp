#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/types.h>
#include <cerrno>
#include <cstring>

int main(){

	// create array to keep pipe descriptors
	int pipefd[2];

	// create pipe
	int pipeResult = pipe(pipefd);

	// check if failed
	if(pipeResult != 0){
		exit(errno);
	}

	// the string to send
	const char* str = "Hello World";

	// size of string to write
	int size = strlen(str);

	// the buffer to read in
	char* buffer = new char[size + 1]; 	

	// write string to pipe's write end
	int written = write(pipefd[1], str, size + 1);  	

	// read N bytes from pipe's read end
	int readBytes = read(pipefd[0], buffer, size + 1);		

	std::cout << "Got from pipe: " << (const char*) buffer << std::endl;

	return 0;
}
