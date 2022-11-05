#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <cerrno>
#include <sys/wait.h>

int main(){

	std::cout << "Parent process started... " << std::endl;
	
	// create child process
	pid_t child = fork();

	// could not create
	if(child == -1){
		return errno;
	}

	// child will be equal to 0 only in child process
	if(child == 0){
		std::cout << "Child process says hello. PID: " << getpid() << std::endl;
	}
	else if(child > 0){
		std::cout << "This will only be executed in parent process. PID: " << getpid() << std::endl;
	}

	std::cout << "General hello from " << getpid() << std::endl;

	// wait for child only in parent
	if(child > 0){
		int childStatus = -1;
		pid_t waitingChildPid = waitpid(child, &childStatus, 0);
		std::cout << "Child process is over, we can complete parent as well. Child process exit code " << childStatus << std::endl;
	}

	std::cout << "Completing process " << getpid() << std::endl;

	return 0;
}
