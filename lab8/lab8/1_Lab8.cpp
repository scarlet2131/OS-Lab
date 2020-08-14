#include <bits/stdc++.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> 

using namespace std;

// void *customer(void *num);
// void *barber(void *);
 void randomwait(int secs);
sem_t wait_for_room;
sem_t chair;
sem_t slp;
sem_t customerwait;
int finished = 0;
void randomwait(int secs) {
     int len = 1;
     sleep(len);
}
void *customer(void *number) {
     int num = *(int *)number;
     printf("Customer %d leaves for b_shop.\n", num);
     randomwait(5);
     printf("Customer %d arrives at b_shop.\n", num); 
     sem_wait(&wait_for_room);
     printf("Customer %d enters wait_room.\n", num); 
     sem_wait(&chair); 
     sem_post(&wait_for_room); 
     printf("Customer %d wakes the_barber.\n", num);
     sem_post(&slp);
     sem_wait(&customerwait);
     sem_post(&chair);
     printf("Customer %d leavs b_shop.\n", num);
}

void *barber(void *junk)
{

  
  while (!finished) { 
    printf("Still slping \n");
    sem_wait(&slp); 
    if (finished==1)
    {
     printf("work over barber_going.\n");
    }
    else {
         
         printf("b_Cutting hair\n");
     randomwait(3);
     printf("b_finished Cutting hair.\n");
     sem_post(&customerwait);
    }
   }
}
   




int main(int argc, char *argv[])
{
    int MAX_CUSTOMERS;
    cout<<"MAXIMUM Possible customer:"<<endl;
    cin>>MAX_CUSTOMERS;
    pthread_t barber_id;
    pthread_t cust_id[MAX_CUSTOMERS];
    int i, x1,x2, number_of_coust, numChairs; 
    int num[MAX_CUSTOMERS];
    printf("Number of customers and chairs.\n");
    scanf("%d",&x1);
    number_of_coust = x1;
    scanf("%d",&x2);
    numChairs = x2;
    //semaphore initialization
            sem_init(&wait_for_room, 0, numChairs);
            sem_init(&chair, 0, 1);
            sem_init(&slp, 0, 0);
            sem_init(&customerwait, 0, 0);
    if (number_of_coust > MAX_CUSTOMERS) {
       printf("The maximum num_customer %d.\n", MAX_CUSTOMERS);
       system("PAUSE");   
       return 0;
    }
    //printf("A solution to the slping barber problem using semaphores.\n");
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        num[i] = i;
    }
    
    
   
    
    pthread_create(&barber_id, NULL, barber, NULL);
   
    
    for (i = 0; i < number_of_coust; i++) {
        pthread_create(&cust_id[i], NULL, customer, (void *)&num[i]);
    }
    
    for (i = 0; i < number_of_coust; i++) {
        pthread_join(cust_id[i],NULL);
    }
    
    finished = 1;
    sem_post(&slp);
    pthread_join(barber_id,NULL);
    system("PAUSE");   
    return 0;
}


