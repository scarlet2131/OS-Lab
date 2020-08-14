


#include<iostream>
#include<stdio.h> // for normal IO and perror()
#include<sys/types.h> // for data type pid_t
#include<sys/wait.h> // for wait() system call
#include<unistd.h>      // for fork(), exit() system call and NULL
#include<stdlib.h> // for abort()
using namespace std;
struct node
{
	int data;
	node *next;
};
typedef struct node node;
int main()
{
	int count,ch=1;
	pid_t pid,pid2;
	pid=fork();
	//pid2=fork();
	node *temp,*last=NULL,*head=NULL;
	//printf("Enter size of queue: ");
	//cin>>n;
	if(pid<0)
	{
		perror("fork");
		abort();
	}
	else if(ch==1&&pid==0)
	{
		printf("I am in child\n");
		printf("Enter number of values you want to enter in the queue: ");
                cin>>count;
                for(int i=0;i<count;i++)
                {
                        int a;
                        cin>>a;
                        temp=(node *)malloc(sizeof(node));
                        temp->data=a;
                        if(last==NULL)
                        {
                                last=temp;
                                temp->next=last;
                                head=temp;
                                //cout<<last->data<<'\n';
                        }
                        else
                        {
                                temp->next=last;
                                //cout<<last->data<<'\n';
                                last->next=temp;
                                last=temp;
                        }
                }
             //   cout<<"Queue is full now!"<<'\n';
		return 0;
		ch=2;
	}
	else if(ch==2&&pid==0)
	{
		cout<<"I am in child two now"<<endl;
	}
	else 
	{
		printf("I am in parent ");
		wait(NULL);
	}
	return 0;
}

