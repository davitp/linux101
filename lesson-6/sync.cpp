#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <semaphore.h>


class Integer{

private:
	int value;
	sem_t* semaphore;
	
public:
	Integer(int val) : value(val){
		this->semaphore = new sem_t();
		sem_init(this->semaphore, 0, 1);
	}
	
	int getValue(){
		return this->value;
	}

	void setValue(int value){
		this->value = value;
	}
	
	void increment(){
		sem_wait(this->semaphore);
		this->value++;
		sem_post(this->semaphore);
	}

	~Integer(){
		sem_destroy(this->semaphore);
		delete this->semaphore;
	}
};

void* increment(void* arg){

	// cast to a known argument type
	Integer* intArg = (Integer*) arg;

	// number of increments
	int increments = 10000;

	// increment integer N times
	for(int i = 0; i < increments; ++i){
		intArg->increment();
	}
	
	return NULL;
}


int main(){

	// creates a new object in heap
	Integer* integer = new Integer(0);

	// number of threads
	int threadsCount = 32;
	
	// create an array of threads
	pthread_t* threads = new pthread_t[threadsCount];

	// create threads to execute in parallel
	for(int i = 0; i < threadsCount; ++i){
		
		// create a thread to execute
		int result = pthread_create(&threads[i], NULL, increment, (void*) integer);
		
		// something went wrong, exiting
		if(result != 0){
			exit(result);
		}
	}
	
	std::cout << "Hanging for a while ... " << std::endl;
	
	// wait for all the threads to complete
	for(int i = 0; i < threadsCount; ++i){
		
		// the return value of thread
		void* retVal;
		
		// join the tread
		pthread_join(threads[i], &retVal);
	}
	
	std::cout << "The current value: " << integer->getValue() << std::endl;

	// remove allocated array from heap
	delete [] threads;
	
	// delete integer from heap
	delete integer;
	
	return 0;
}
