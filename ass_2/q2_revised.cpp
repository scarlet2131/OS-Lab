#include<bits/stdc++.h>
#include<stdio.h> // for normal IO and perror()
#include<sys/types.h> // for data type pid_t
#include<sys/wait.h> // for wait() system call
#include<unistd.h>	// for fork(), exit() system call and NULL
#include<stdlib.h> // for abort()
using namespace std;
int n1;
#define BUFFER_SIZE n1
// typedef struct
// {
// 	int data;
// } item;

struct Node 
{ 
	int data; 
	struct Node* link; 
}; 

struct Queue 
{ 
	struct Node *front, *rear; 
}; 

// Function to create Circular queue 
void enQueue(Queue *q, int value) 
{ 
	struct Node *temp = new Node; 
	temp->data = value; 
	if (q->front == NULL) 
		q->front = temp; 
	else
		q->rear->link = temp; 

	q->rear = temp; 
	q->rear->link = q->front; 
} 

// Function to delete element from Circular Queue 
int deQueue(Queue *q) 
{ 
	if (q->front == NULL) 
	{ 
		printf ("Queue is empty"); 
		return INT_MIN; 
	} 

	// If this is the last node to be deleted 
	int value; // Value to be dequeued 
	if (q->front == q->rear) 
	{ 
		value = q->front->data; 
		free(q->front); 
		q->front = NULL; 
		q->rear = NULL; 
	} 
	else // There are more than one nodes 
	{ 
		struct Node *temp = q->front; 
		value = temp->data; 
		q->front = q->front->link; 
		q->rear->link= q->front; 
		free(temp); 
	} 

	return value ; 
} 

// Function displaying the elements of Circular Queue 
void displayQueue(struct Queue *q,int n2) 
{ 
	int c=0;
	struct Node *temp = q->front; 
	printf("\nElements in Circular Queue are: "); 
	while (temp->link != q->front) 
	{ 
		int c++;
		printf("%d ", temp->data); 
		temp = temp->link; 
		if(c==n2)
		{
			break;
		}
	} 
	printf("%d", temp->data); 
} 

int main()
{item Buffer[BUFFER_SIZE],items;
	
	Queue *q = new Queue; 
	q->front = q->rear = NULL; 


	cin>>n1;
	int n2;
	cin>>n2;
	
	int x;
	int in=0,out=0;
	int fd[2],i=0;
	pipe(fd);
	pid_t pid1,pid2;
	pid1=fork();
	if (pid1 < 0) 
	{
		perror("fork"); 		
		abort(); 
	}	
	else if(pid1 == 0) 
	{
		printf("I am in child process\n");
		for(int i=0;i<n1;i++)
		{
			cin>>x;
			enQueue(q,x);


					//fib(n,a,k);
			// while(true)
			// {
			// 	while(((in+1)%n1)==out)
			// 	{
			// 		cout<<"queue is full"<<endl;
			// 		break;
			// 	}

			// 	enQueue(q,item);
			// 	in=(in+1)%n1;
			// 			//exit(in);
			// }
		}





		close(fd[0]);
		close(1);
		dup(fd[1]);


		write(1,Buffer,sizeof(Buffer));



		return 0;	
	}

	else 
	{
		pid2=fork();
		if (pid2 < 0) 
		{
			perror("fork"); 		
			abort(); 
		}	
		else if(pid2 == 0) 
		{
			printf("I am in child process\n");

				//fib(n,a,k);
			close(0);
			close(fd[1]);
			dup(fd[0]);
			int l=read(fd[0],Buffer,sizeof(Buffer));	


			while(true)
			{
				while(in==out)
				{
					cout<<"queue is empty"<<endl;
					break;
				}
				items.data=Buffer[out].data;
				out=out+1%n2;
				return items.data;

			}

				/*close(fd[0]);
				close(1);
				dup(fd[1]);


				 write(1,a,sizeof(a));*/



			return 0;	
		}
		else 
		{


			printf("I am in parent\n");
			wait(NULL);	



			printf("child terminated");
		}
		

		printf("I am in parent\n");
		wait(NULL);
		printf("child terminated");
	}
	return 0;
}
