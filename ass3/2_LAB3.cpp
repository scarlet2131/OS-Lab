#include<bits/stdc++.h>
using namespace std;
struct node
{
  int pid;
  int burst_t;
  int io_burst_t;
  int wait_t;
  int arrival_t;
  int ta_t;

  struct node * next;
};

node *newNode(int i0,int i1,int i2,int i3,int i4,int i5)
{
  node* temp=new node;
  temp->pid=i0;
  temp->burst_t=i1;
  temp->io_burst_t=i2;
  temp->wait_t=i3;
  temp->arrival_t=i4;
  temp->ta_t=i5;
  temp->next=NULL;
  return temp;
}
node *insert(node* root,int i0,int i1,int i2,int i3,int i4,int i5)
{
  if(root==NULL)
  {
    return newNode(i0,i1,i2,i3,i4,i5);
  }
  node* temp=newNode(i0,i1,i2,i3,i4,i5);
  temp->next=NULL;
  node* itr=root;
  while(itr->next!=NULL)
  {
    itr=itr->next;
  
  }
  itr->next = temp;
  return root;

}

int main()
{
  while(1)
  {
    cout<<"1. FCFS\n2. SJF\n3. RR\n4. Priority\nEnter Choice:";
    int n;
    cin>>n;
    if(n==1)
    {
      int w = 0;
      node *root = NULL;
      int np;
      cout<<"Enter no of processes:";
      cin>>np;
      for(int i=0;i<np;i++)
      {
        cout<<"\nEnter Arrival Time of P"<<i<<": ";
        int arr;
        cin>>arr;
        cout<<"Enter Burst Time of P"<<i<<": ";
        int burst;
        cin>>burst;
        cout<<"Enter I/O Birst Time of P"<<i<<": ";
        int io;
        cin>>io;
	 w = w + burst;
        root = insert(root,i+1,burst,io,w,arr,w+arr);
       
      }

      node *itr = root;
      int sum=0;
      printf("\nProcess\t   Arrival\t    Burst Time    \tWaiting Time\tTurnaround Time");
      while(itr!=NULL)
      {
        sum+=itr->wait_t;
        printf("\nP[%d]\t\t%d\t\t  %d\t\t    %d\t\t\t%d",itr->pid,itr->arrival_t,itr->burst_t,itr->wait_t,itr->ta_t);

        itr = itr->next;

      }
      float avg_wait=sum/n;
      cout<<avg_wait;
      cout<<endl;
    }
    else if(n==2)
    {

    }
  

  }
}
