#include<bits/stdc++.h>
using namespace std;
struct Node 
{ 
  int data; 
  struct Node *next; 
}; 
  
int i=0;
void insertAfter(struct Node* prev_node, int new_data,int n1,int in) 
{ 
   
    if (prev_node == NULL) 
    { 
      printf("the given previous node cannot be NULL"); 
      return; 
    } 

	 while(in<=n1)
	  {
	   
	    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 
	  
	   
	    new_node->data  = new_data; 
	  
	   
	    new_node->next = prev_node->next; 
	  
	    
	    prev_node->next = new_node; 
	    	}
} 
void printList(struct Node* node,int out,int n2) 
{ 
  while (out<=n2); 
  { 
     printf(" %d ", node->data); 
     node = node->next; 
  } 
}


int main()
{
	struct Node* head=NULL;
	int n1;
	cin>>n1;
	int n2;
	cin>>n2;
	int in=0,out=0;
	int item;
	for(int i=0;i<n1;i++)
	{
		cin>>item;
	

		struct node* new_node=NULL;
		new_node=(struct node*)malloc(sizeof(struct Node));
		int in=0;
		int out=0;
		while(true)
		{
			int is_full = 0;
			while(((in+1)%n1)==out)
			{
				cout<<"queue is full"<<endl;
				is_full = 1;
				break;
			}
			if(is_full==1)
				break;
			insertAfter(head,item,n1,in);
			in=(in+1)%n1;
		}
		
	}

	for(int i=0;i<n2;i++)
	{
		cin>>item;
		
		while(true)
		{
			while(in==out)
			{
				cout<<"queue is empty"<<endl;
			}
			printList(head,out,n2);
			out=out+1%n2;
			
		}
	

	}
	
}