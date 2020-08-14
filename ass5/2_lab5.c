#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include<unistd.h>


//#define N 5
#define THINKING 2 
#define HUNGRY 1 
#define EATING 0 

int N;

int state[100]; 
int phil[100] ; 
int x=0;
sem_t mutex; 
sem_t S[100]; 

void test(int phnum) 
{ 
	if (state[phnum] == HUNGRY 
		&& state[(phnum + 4) % N ] != EATING 
		&& state[(phnum + 1) % N ] != EATING) { 
		// state that eating 
		state[phnum] = EATING; 

		sleep(2); 

		printf("Philosopher %d takes fork %d and %d\n", 
					phnum + 1, (phnum + 4) % N  + 1, phnum + 1); 

		printf("Philosopher %d is Eating\n", phnum + 1); 

		// sem_post(&S[phnum]) has no effect 
		// during takefork 
		// used to wake up hungry philosophers 
		// during putfork 
		sem_post(&S[phnum]); 
	} 
} 

// take up chopsticks 
void take_fork(int phnum) 
{ 

	sem_wait(&mutex); 

	// state that hungry 
	state[phnum] = HUNGRY; 

	printf("Philosopher %d is Hungry\n", phnum + 1); 

	// eat if neighbours are not eating 
	test(phnum); 

	sem_post(&mutex); 

	// if unable to eat wait to be signalled 
	sem_wait(&S[phnum]); 

	sleep(1); 
} 

// put down chopsticks 
void put_fork(int phnum) 
{ 

	sem_wait(&mutex); 

	// state that thinking 
	state[phnum] = THINKING; 

	printf("Philosopher %d putting fork %d and %d down\n", 
		phnum + 1, (phnum + 4) % N + 1, phnum + 1); 
	printf("Philosopher %d is thinking\n", phnum + 1); 

	test((phnum + 4) % N ); 
	test((phnum + 1) % N ); 

	sem_post(&mutex); 
} 

void* philospher(void* num) 
{ 

	while (1) { 
		x++;
		int *i = *(int*)num; 

		sleep(1); 

		take_fork(*i); 

		sleep(0); 

		put_fork(*i); 
		if(x==N)
		{
			break;
		}
	} 
} 

int main() 
{ 
	
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		phil[i]=i;
	}
	int i; 
	pthread_t thread_id[N]; 

	// initialize the semaphores 
	sem_init(&mutex, 0, 1); 

	for (i = 0; i < N; i++) 

		sem_init(&S[i], 0, 0); 

	for (i = 0; i < N; i++) { 

		// create philosopher processes 
		pthread_create(&thread_id[i], NULL, 
					philospher, &phil[i]); 

		printf("Philosopher %d is thinking\n", i + 1); 
	} 

	for (i = 0; i < N; i++) 

		pthread_join(thread_id[i], NULL); 
} 

