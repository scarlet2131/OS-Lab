#include<bits/stdc++.h> 
using namespace std; 

struct Queue 
{ 
	// Initialize front and rear 
	int rear, front; 

	// Circular Queue 
	int size; 
	int *arr; 

	Queue(int s) 
	{ 
	front = rear = -1; 
	size = s; 
	arr = new int[s]; 
	} 

	void enQueue(int value); 
	int deQueue(); 
	void displayQueue(int p); 
}; 


/* Function to create Circular queue */
void Queue::enQueue(int value) 
{ 
	if ((front == 0 && rear == size-1) || 
			(rear == (front-1)%(size-1))) 
	{ 
		printf("Queue is Full\n"); 
		return; 
	} 

	else if (front == -1) /* Insert First Element */
	{ 
		front = rear = 0; 
		arr[rear] = value; 
	} 

	else if (rear == size-1 && front != 0) 
	{ 
		rear = 0; 
		arr[rear] = value; 
	} 

	else
	{ 
		rear++; 
		arr[rear] = value; 
	} 
} 
int Queue::deQueue() 
{ 
    if (front == -1) 
    { 
        printf("Queue is Empty\n"); 
        return INT_MIN; 
    } 
  
    int data = arr[front]; 
    arr[front] = -1; 
    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front++; 
  
    return data; 
} 
void Queue::displayQueue(int p) 
{ 
	if (front == -1) 
	{ 
		printf("Queue is Empty\n"); 
		return; 
	} 
	printf("\nElements in Circular Queue are: "); 
	if (rear >= front) 
	{ 
		for (int i = front; i <= rear && i<p; i++) {
			printf("%d ",arr[i]); }
		cout<<endl;
	} 
	else
	{ 
		for (int i = front; i < p; i++) 
			printf("%d ", arr[i]); 

		for (int i = 0; i <= p; i++) 
			printf("%d ", arr[i]); 
	} 
} 
Queue q(50);
void *my_queue(void *) 
{ 
	int n;
	cout<<"How many no you want to insert?"<<endl;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		q.enQueue(x);
	}
	printf("Queue is Full.\n"); 
} 

void *print_q(void *) 
{ 
	int p;
	cout<<"How many no you want to print? "<<endl;
	cin>>p;
	q.displayQueue(p);
} 
/* Driver of the program */
int main() 
{ 
	 
	pthread_t tid,t1,t2,t3; 
  
        pthread_create(&tid, NULL, my_queue,NULL); 
	pthread_join(tid,NULL);
	pthread_create(&t1, NULL, print_q,NULL);
    pthread_exit(NULL); 
	return 0; 
} 

