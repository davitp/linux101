#include <iostream>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

void handleAbort(int signum, siginfo_t* siginfo, void* context){

	std::cout << "Abort signal is recived from " << siginfo->si_pid << std::endl;
//	exit(0);
}

int main(){ 

	struct sigaction new_sigaction;
	memset(&new_sigaction, 0, sizeof(struct sigaction));

	new_sigaction.sa_sigaction = handleAbort;

	sigaction(SIGABRT, &new_sigaction, NULL);

	while(true){
		sleep(2);
		std::cout << "Working..." << std::endl;	
	}

	return 0;
}
