#include <pthread.h>
#include <iostream>
#include <sys/types.h>


void* threadFunction(void* arg){
	
	while(true){
		std::cout << "+";
	}

	return NULL;
}


int main(){

	std::cout << "Hello from main thread... " << std::endl;

	// the thread we create
	pthread_t tid;

	// create thread to run threadFunction routine
	int threadCreated = pthread_create(&tid, NULL, threadFunction, NULL); 

	// check if created succesfuly
	if(threadCreated != 0){
		std::cerr << "Could not create new thread" << std::endl;
		return threadCreated;
	}

	// print in main thread
	while(true){
		std::cout << "-";
	}

	// return value of thread
	void* retval;

	// join the thread and get its return value
	int joinResult = pthread_join(tid, &retval);

	return 0;
}
