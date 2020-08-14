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
	int priority;
	struct node * next;
};

node *newNode(int i0,int i1,int i2,int i3,int i4,int i5,int i6)
{
	node* temp=new node;
	temp->pid=i0;
	temp->burst_t=i1;
	temp->io_burst_t=i2;
	temp->wait_t=i3;
	temp->arrival_t=i4;
	temp->ta_t=i5;
	temp->priority = i6;
	temp->next=NULL;
	return temp;
}
node *insert(node* root,int i0,int i1,int i2,int i3,int i4,int i5,int i6)
{
	if(root==NULL)
	{
		return newNode(i0,i1,i2,i3,i4,i5,i6);
	}
	node* temp=newNode(i0,i1,i2,i3,i4,i5,i6);
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
		cout<<"1. FCFS\n2. SRTF\n3. RR\n4. Priority Sched.\nEnter Choice:";
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

				root = insert(root,i+1,burst,io,w,arr,w+arr+burst,0);
				w = w + burst;
			}

			cout<<"Running FCFS.....\n";
			node *itr = root;
			int sum=0;
			printf("\nProcess\t   Arrival\t    Burst Time    \tWaiting Time\tTurnaround Time");
			while(itr!=NULL)
			{
				sum+=itr->wait_t;
				printf("\nP[%d]\t\t%d\t\t  %d\t\t    %d\t\t\t%d",itr->pid,itr->arrival_t,itr->burst_t,itr->wait_t,itr->ta_t);

				itr = itr->next;

			}
			cout<<endl;
			float avg_wait=(double)sum/n;
			cout<<avg_wait;
			cout<<endl<<endl;
		}
		else if(n==2)
		{
			node *root = NULL;
			node *root2 = NULL;
			
			
			int w = 0;
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

				root = insert(root,i+1,burst,io,0,arr,0,0);
				root2 = insert(root2,i+1,burst,io,0,arr,0,0);
			}

			cout<<"Running SRTF.....\n";
			// check by incrementing time one by one
			int complete[100];
			int cc = 0;
			int t = 0;
			int min=INT_MAX;
			while(true)
			{

				node *itr = root;
				

				node *run;					//will store the process that will run
				int found = 0;
				while(itr!=NULL)
				{
					if(itr->arrival_t<=t && itr->burst_t<=min && itr->burst_t>0)
					{
						min = itr->burst_t;
						run = itr;
						found = 1;
					}
					itr=itr->next;
				}
				if(found == 0)
				{
					t++;
					continue;
				}

				run->burst_t = run->burst_t - 1;
				min = run->burst_t;
				if(min<=0)
					min = INT_MAX;

				if(run->burst_t<=0)
				{
					complete[cc++] = run->pid;
					if(cc==np)
						break;
					found = 0;
					int finish = t+1;

					// find burst time of that pid (because we have modified)
					node *itr2 = root2;
					int act_burst=0;
					while(itr2!=NULL)
					{
						if(itr2->pid == run->pid)
						{
							act_burst = itr2->burst_t;
							break;
							
						}
						itr2=itr2->next;
					}

					run->wait_t = finish - act_burst - run->arrival_t;
					if(run->wait_t<0)
						run->wait_t = 0;

				}
				
				t++;
				
			}

			//calculate TAT and avg time.
			node *itr = root;
			node *itr2 = root2;
			while(itr!=NULL && itr2!=NULL)
			{
				itr->ta_t = itr2->burst_t + itr->wait_t;
				itr=itr->next;
				itr2=itr2->next;
			}
			
			double tw = 0;
			double t_tat = 0;
			itr = root;
			itr2 = root2;
			printf("\nProcess\t   Arrival\t    Burst Time    \tWaiting Time\tTurnaround Time");
			while(itr!=NULL)
			{
				printf("\nP[%d]\t\t%d\t\t  %d\t\t    %d\t\t\t%d",itr->pid,itr->arrival_t,itr2->burst_t,itr->wait_t,itr->ta_t);
				tw = tw + itr->wait_t;
				t_tat = t_tat + itr->ta_t;

				itr=itr->next;
				itr2 =itr2->next;
			}
			cout<<"\nAvg. Waiting Time: "<<(double)tw/(np)<<endl;
			cout<<"Avg TAT: "<<(double)t_tat/np<<endl;

			cout<<"Process of accessing CPU': ";
			for(int i=0;i<cc;i++)
			{
				cout<<complete[i]<<" ";
			}
			cout<<endl<<endl;


		}

		else if(n==3)
		{
			node *root = NULL;
			node *root2 = NULL;

			int np;
			cout<<"Enter no of processes:";
			cin>>np;
			cout<<"Enter Quantum for RR: ";
			int quanta;
			cin>>quanta;
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

				root = insert(root,i+1,burst,io,0,arr,0,0);
				root2 = insert(root2,i+1,burst,io,0,arr,0,0);
			}

			cout<<"Running RR.....\n";
			int complete[100];
			int cc=0;
			int t=0;
			while(1)
			{
				bool done = true;
				node *itr = root;
				while(itr!=NULL)
				{
					if(itr->burst_t>0)
					{
						done  = false;
						if(itr->burst_t>quanta)
						{
							t += quanta;
							itr->burst_t -= quanta;
						}

						else
						{
							//time slice rem is smaller than quanta, it will be completed in this cycle;
							complete[cc++] = itr->pid;
							t = t + itr->burst_t;
							node *itr2 = root2;
							int act_burst=0;
							while(itr2!=NULL)
							{
								if(itr2->pid == itr->pid)
								{
									act_burst = itr2->burst_t;
									break;
								}
								itr2=itr2->next;
							}

							itr->wait_t = t - act_burst;
							itr->burst_t = 0;
						}
					}
					
					itr = itr->next;
				}

				if(done == true)
					break;
			}

			node *itr = root;
			node *itr2 = root2;
			while(itr!=NULL && itr2!=NULL)
			{
				itr->ta_t = itr2->burst_t + itr->wait_t;
				itr=itr->next;
				itr2=itr2->next;
			}

			double tw = 0;
			double t_tat = 0;
			itr = root;
			itr2 = root2;
			printf("\nProcess\t   Arrival\t    Burst Time    \tWaiting Time\tTurnaround Time");
			while(itr!=NULL)
			{
				printf("\nP[%d]\t\t%d\t\t  %d\t\t    %d\t\t\t%d",itr->pid,itr->arrival_t,itr2->burst_t,itr->wait_t,itr->ta_t);
				tw = tw + itr->wait_t;
				t_tat = t_tat + itr->ta_t;

				itr=itr->next;
				itr2 =itr2->next;
			}
			cout<<"\nAvg. Waiting Time: "<<(double)tw/(np)<<endl;
			cout<<"Avg TAT: "<<(double)t_tat/np<<endl;

			cout<<"Process of accessing CPU': ";
			for(int i=0;i<cc;i++)
			{
				cout<<complete[i]<<" ";
			}
			cout<<endl<<endl;

		}
		else if(n==4)
		{
			node *root = NULL;
			node *root2 = NULL;
			
			
			int w = 0;
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
				cout<<"Enter priority: ";
				int pr;
				cin>>pr;

				root = insert(root,i+1,burst,io,0,arr,0,pr);
				root2 = insert(root2,i+1,burst,io,0,arr,0,pr);
			}

			cout<<"Running Priority Queue.....\n";


			int complete[100];
			int cc=0;

			int total = 0;
			for(int i=0;i<100;i++)
			{
				bool found = false;
				node *itr = root;
				int min = INT_MAX;

				node *run;
				while(itr!=NULL)
				{
					if(itr->priority<=min && itr->priority>=0)
					{
						found = true;
						run = itr;
						min = itr->priority;
						
						
					}
					itr=itr->next;
				}

				if(found == false)
					break;
				if(i==0)
				{
					complete[cc++] = run->pid;
					run->priority = -1;
					total += run->burst_t;
					run->wait_t = 0;
					run->ta_t = run->wait_t + run->burst_t;
				}
				else
				{
					complete[cc++] = run->pid;
					run->priority = -1;
					run->wait_t = total;
					total += run->burst_t;
					
					run->ta_t = run->wait_t + run->burst_t;
				}
				
				
			}
			
			node *itr = root;
			double tw = 0;
			double t_tat = 0;
			printf("\nProcess\t   Arrival\t    Burst Time    \tWaiting Time\tTurnaround Time");
			while(itr!=NULL)
			{
				printf("\nP[%d]\t\t%d\t\t  %d\t\t    %d\t\t\t%d\t",itr->pid,itr->arrival_t,itr->burst_t,itr->wait_t,itr->ta_t);
				tw = tw + itr->wait_t;
				t_tat = t_tat + itr->ta_t;

				itr=itr->next;
				
			}
			cout<<"\nAvg. Waiting Time: "<<(double)tw/(np)<<endl;
			cout<<"Avg TAT: "<<(double)t_tat/np<<endl;

			cout<<"Process of accessing CPU': ";
			for(int i=0;i<cc;i++)
			{
				cout<<complete[i]<<" ";
			}
			cout<<endl<<endl;
		}


	}
}




/*
example of shortest remainging first
Processes  Burst time  	Waiting time  Turn around time
 1        		6         3        		9
 2        		8         16        		24
 3        		7         8        		15
 4        		3         0        		3
Average waiting time = 6.75
Average turn around time = 12.75
*/


/*
eg for RR
quanta = 2;
Processes  Burst time  Waiting time  Turn around time
 1        	10    		 13        		23
 2        	5    		 10         	15
 3        	8     		 13         	21
Average waiting time = 12
Average turn around time = 19.6667
*/
