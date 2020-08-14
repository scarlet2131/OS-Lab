#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
struct pcb
{
	int arr,priority,burst_time,device,d1,d2;
	int cpu_burst,exit,wait,response;
	string name;
};
typedef struct pcb pcb;
/*struct ready
  {
  pcb *data;
  struct ready *next;
  }
  typedef struct ready ready;
  struct device
  {
  pcb *data;
  struct ready *next;
  }
  typedef struct device device;*/
bool com(pcb a,pcb b)
{
	return (a.arr<=b.arr);
}
bool com1(pcb a,pcb b)
{
	return (a.cpu_burst<=b.cpu_burst);
}
bool com2(pcb a,pcb b)
{
	return (a.priority<=b.priority);
}
int main()
{
	int ch,n,bt,flag,at,ar,aw,i,tem[100],clock,terminated,x,ch1,j,z;
	pcb process[100];
	string kill[100];
	int check[100];
	cout<<"Enter 1 for FCFS ,2 for SRTF,3 for Priority,4 for Round Robin"<<'\n';
	cin>>ch;
	cout<<"enter no of process"<<'\n';
	cin>>n;
	cout<<"enter burst time"<<'\n';
	cin>>bt;
	switch(ch)
	{
		case 1:
			//cout<<"enter no of process"<<'\n';
			//cin>>n;
			//cout<<"enter burst time"<<'\n';
			//cin>>bt;
			for(i=0;i<n;i++)
			{
				cout<<"Enter name"<<'\n';
				cin>>process[i].name;
				cout<<"Enter arrival time of P"+i<<'\n';
				cin>>process[i].arr;
				//j++;
				cout<<"Enter no of cpu bursts"<<'\n';
				cin>>process[i].cpu_burst;
			}
			sort(process,process+n,com);
                        for(i=0;i<n;i++)
			{
				tem[i]=process[i].cpu_burst;
				check[i]=0;

			}
			/*for(i=0;i<n;i++)
			  {
			  temp=(ready *)malloc(sizeof(ready));
			  temp->data=process[i];
			  }*/
			clock=0;
			i=0;
			terminated=0;

			while(terminated!=n)	
			{
				flag=0;
				for(x=0;x<terminated;x++)
				{
					if(kill[x].compare(process[i].name)==0)
						flag=1;
				}
				if(flag==0)
				{	
					cout<<process[i].name<<" is executing in cpu"<<'\n';
					if(check[i]==0)
					{
						process[i].response=clock-process[i].arr;
						check[i]=1;
					}
					clock+=bt;
					process[i].cpu_burst--;
					if(process[i].cpu_burst==0)
					{
						process[i].exit=clock;
						kill[terminated]=process[i].name;
						terminated++;
					}
					else
						cout<<process[i].name<<" device queue"<<'\n';

				}
				i=(i+1)%n;
			}
			at=0;
			aw=0;
			ar=0;
			for(i=0;i<n;i++)
			{
				cout<<process[i].name<<'\n';
				cout<<"Arrival time :"<<process[i].arr<<'\n';
				cout<<"Exit time :"<<process[i].exit<<'\n';
				at+=process[i].exit-process[i].arr;
				cout<<"TAT :"<<process[i].exit-process[i].arr<<'\n';
				//cout<<process[i].cpu_burst<<'\n';
				aw+=(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt);
				ar+=process[i].response;
				cout<<"WT :"<<(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt)<<'\n';
				cout<<"RT :"<<process[i].response<<'\n';

			}
			//break;
			//default:
			//cout<<"error"<<'\n';
			cout<<"Average tat :"<<(at/n)<<'\n';
			cout<<"Average wt :"<<(aw/n)<<'\n';
			cout<<"Average rt :"<<(ar/n)<<'\n';
			break;
		        case 2:

			cout<<"Enter 1 for non preemptive 2 for preemptive"<<'\n';
			cin>>ch1;
			if(ch1==1)
			{
				for(i=0;i<n;i++)
				{
					cout<<"Enter name"<<'\n';
					cin>>process[i].name;
					cout<<"Enter arrival time"<<'\n';
					cin>>process[i].arr;
					cout<<"Enter no of cpu bursts"<<'\n';
					cin>>process[i].cpu_burst;
				}
				sort(process,process+n,com1);
				clock=0;
				terminated=0;
				for(i=0;i<n;i++)
					tem[i]=process[i].cpu_burst;
				i=0;
				while(terminated!=n)
				{
					if(process[i].arr<=clock)
					{
						for(x=0;x<terminated;x++)
						{
							if(kill[x].compare(process[i].name)==0)
								flag=1;
						}
						if(flag==0)
						{
							cout<<process[i].name<<" is executing in cpu"<<'\n';
							if(check[i]==0)
							{
								process[i].response=clock-process[i].arr;
								check[i]=1;
							}
							clock+=bt;
							process[i].cpu_burst--;
							if(process[i].cpu_burst==0)
							{
								process[i].exit=clock;
								kill[terminated]=process[i].name;
								terminated++;
								cout<<process[i].name<<" Terminated"<<'\n';
							}
							else
								cout<<process[i].name<<" device queue"<<'\n';
						}
					}
					i=(i+1)%n;
				}
				at=0;
				ar=0;aw=0;
				for(i=0;i<n;i++)
				{
					cout<<process[i].name<<'\n';
					cout<<"Arrival time :"<<process[i].arr<<'\n';
					cout<<"Exit time :"<<process[i].exit<<'\n';
					at+=process[i].exit-process[i].arr;
					cout<<"TAT :"<<process[i].exit-process[i].arr<<'\n';
					aw+=(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt);
					ar+=process[i].response;
					cout<<"WT :"<<(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt)<<'\n';
					cout<<"RT :"<<process[i].response<<'\n';


				}
				cout<<"AT :"<<at/n<<'\n';
				cout<<"AW :"<<aw/n<<'\n';
				cout<<"AR :"<<ar/n<<'\n';

			}
			else
			{
				for(i=0;i<n;i++)
				{
					process[i].burst_time=bt;
					cout<<"Enter process name"<<'\n';
					cin>>process[i].name;
					cout<<"Enter arrival time"<<'\n';
					cin>>process[i].arr;
					cout<<"Enter cpu burst"<<'\n';
					cin>>process[i].cpu_burst;
					process[i].device=0;
					process[i].d2=-1;

				}
				sort(process,process+n,com1);
				for(i=0;i<n;i++)
					tem[i]=process[i].cpu_burst; 
				clock=0;
				terminated=0;
				i=0;
				while(terminated!=n)
				{
					for(j=0;j<n;j++)
					{
						flag=0;
						z=0;
						for(x=0;x<terminated;x++)
						{
							if(kill[x].compare(process[j].name)==0)
								flag=1;
						}
						if(process[j].arr<=clock&&flag==0&&process[j].device==0)
						{
							//cout<<process[j].d2;
							z=1;
							break;
						}
					}
					/*flag=0;
					  for(x=0;x<terminated;x++)
					  {
					  if(kill[x].compare(process[j].name)==0)
					  flag=1;
					  }*/
					if(flag==0&&z==1)
					{
						cout<<process[j].name<<" is executing in cpu"<<'\n';
						if(check[j]==0)
						{
							process[j].response=clock-process[j].arr;
							check[j]=1;
						}
						clock++;
						process[j].burst_time--;
						if(process[j].burst_time==0)
						{
							process[j].cpu_burst--;
							if(process[j].cpu_burst!=0)
							{
								cout<<process[j].name<<" device queue"<<'\n';
								process[j].device=1;
								process[j].d2=clock+bt;
								//cout<<process[j].d2;
							}
							process[j].burst_time=bt;
						}
						/*else
						  {
						  for(int k=0;k<n;k++)
						  {
						  flag=0;
						  for(x=0;x<terminated;x++)
						  {
						  if(kill[x].compare(process[j].name)==0)
						  flag=1;
						  }
						  if(process[k].arr==clock
						  cout<<process[j].name<<" device queue"<<'\n'; */
						if(process[j].cpu_burst==0)
						{
							process[j].exit=clock;
							kill[terminated]=process[j].name;
							terminated++;
							cout<<process[j].name<<" Terminated"<<'\n';
						}
						//else
						//cout<<process[j].name<<"Device queue"<<'\n'; 
						for(int y=0;y<n;y++)
						{
							if(clock==process[y].d2)
								process[y].device=0;
						}  

					}
						else
						{
							clock++;
							for(int y=0;y<n;y++)
							{
								if(clock==process[y].d2)
									process[y].device=0;

							}

						}

					}
					at=0;
					aw=0;
					ar=0;
					for(i=0;i<n;i++)
					{
						cout<<process[i].name<<'\n';
						cout<<"Arrival time :"<<process[i].arr<<'\n';
						cout<<"Exit time :"<<process[i].exit<<'\n';
						at+=process[i].exit-process[i].arr;
						cout<<"TAT :"<<process[i].exit-process[i].arr<<'\n';
						aw+=(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt);
						ar+=process[i].response;
						//if(process[i].name.compare("p01")==0)
						//cout<<tem[i]; 
						cout<<"WT :"<<(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt)<<'\n';
						cout<<"RT :"<<process[i].response<<'\n';
					}
					cout<<"AT :"<<at/n<<'\n';
					cout<<"AW :"<<aw/n<<'\n';
					cout<<"AR :"<<ar/n<<'\n';
					}
					break;
					case 3:
					cout<<"Enter 1 for non preemptive 2 for preemptive"<<'\n';
					cin>>ch1;
					if(ch1==1)
					{
						for(i=0;i<n;i++)
						{
							cout<<"Enter name"<<'\n';
							cin>>process[i].name;
							cout<<"Enter arrival time"<<'\n';
							cin>>process[i].arr;
							cout<<"Enter no of cpu bursts"<<'\n';
							cin>>process[i].cpu_burst;
							cout<<"Enter priority"<<'\n';
							cin>>process[i].priority;
						}
						sort(process,process+n,com2);
						clock=0;
						terminated=0;
						for(i=0;i<n;i++)
							tem[i]=process[i].cpu_burst;
						i=0;
						while(terminated!=n)
						{
							if(process[i].arr<=clock)
							{
								for(x=0;x<terminated;x++)
								{
									if(kill[x].compare(process[i].name)==0)
										flag=1;
								}
								if(flag==0)
								{
									cout<<process[i].name<<" is executing in cpu"<<'\n';
									if(check[i]==0)
									{
										process[i].response=clock-process[i].arr;
										check[i]=1;
									}
									clock+=bt;
									process[i].cpu_burst--;
									if(process[i].cpu_burst==0)
									{
										process[i].exit=clock;
										kill[terminated]=process[i].name;
										terminated++;
										cout<<process[i].name<<" is terminated"<<'\n';
									}
									else
										cout<<process[i].name<<" device queue"<<'\n';
								}
							}
							i=(i+1)%n;







						}
						at=0;
						ar=0;aw=0;
						for(i=0;i<n;i++)
						{
							cout<<process[i].name<<'\n';
							cout<<"Arrival time :"<<process[i].arr<<'\n';
							cout<<"Exit time :"<<process[i].exit<<'\n';
							at+=process[i].exit-process[i].arr;
							cout<<"TAT :"<<process[i].exit-process[i].arr<<'\n';
							aw+=(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt);
							ar+=process[i].response;
							cout<<"WT :"<<(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt)<<'\n';
							cout<<"RT :"<<process[i].response<<'\n';




						}
					}
					else
					{
						for(i=0;i<n;i++)
						{
							process[i].burst_time=bt;
							cout<<"Enter process name"<<'\n';
							cin>>process[i].name;
							cout<<"Enter arrival time"<<'\n';
							cin>>process[i].arr;
							cout<<"enter cpu burst"<<'\n';
							cin>>process[i].cpu_burst;
							process[i].device=0;
							process[i].d2=-1;
						}
						sort(process,process+n,com2);
						for(i=0;i<n;i++)
							tem[i]=process[i].cpu_burst;
						clock=0;
						terminated=0;
						i=0;
						while(terminated!=n)
						{
							for(j=0;j<n;j++)
							{
								flag=0;
								z=0;
								for(x=0;x<terminated;x++)
								{
									if(kill[x].compare(process[j].name)==0)
										flag=1;
								}
								if(process[j].arr<=clock&&flag==0&&process[j].device==0)
								{
									z=1;
									break;
								}
								if(flag==0&&z==1)
								{
									cout<<process[j].name<<" is executing in cpu"<<'\n';
									if(check[j]==0)
									{
										process[j].response=clock-process[j].arr;
										check[j]=1;
									}
									clock++;
									process[j].burst_time--;
									if(process[j].burst_time==0)
									{
										process[j].cpu_burst--;
										if(process[j].cpu_burst!=0)
										{
											cout<<process[j].name<<" device queue"<<'\n';
											process[j].device=1;
											process[j].d2=clock+bt;
										}
										process[j].burst_time=bt;
									}
									if(process[j].cpu_burst==0)
									{
										process[j].exit=clock;
										kill[terminated]=process[j].name;
										terminated++;
										cout<<process[j].name<<" Terminated"<<'\n';
									}
									for(int y=0;y<n;y++)
									{
										if(clock==process[y].d2)
											process[y].device=0;
									}
								}
								else
								{
									clock++;
									for(int y=0;y<n;y++)
									{
										if(clock==process[y].d2)
											process[y].device=0;
									}
								}
							}




						}
						at=0;
						aw=0;
						ar=0;
						for(i=0;i<n;i++)
						{
							cout<<process[i].name<<'\n';
							cout<<"Arrival time :"<<process[i].arr<<'\n';
							cout<<"Exit time :"<<process[i].exit<<'\n';
							at+=process[i].exit-process[i].arr;
							cout<<"TAT :"<<process[i].exit-process[i].arr<<'\n';
							aw+=(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt);
							ar+=process[i].response;
							cout<<"WT :"<<(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt)<<'\n';
							cout<<"RT :"<<process[i].response<<'\n';
						}
						cout<<"AT :"<<at/n<<'\n';
						cout<<"AW :"<<aw/n<<'\n';
						cout<<"AR :"<<ar/n<<'\n';



					}
					break;
					case 4:
					int qua;
					cout<<"enter time quantum"<<'\n';
					cin>>qua;
					for(i=0;i<n;i++)
					{
						process[i].burst_time=bt;
						cout<<"Enter name"<<'\n';
						cin>>process[i].name;
						cout<<"Enter arrival time"<<'\n';
						cin>>process[i].arr;
						cout<<"Enter no of cou bursts"<<'\n';
						cin>>process[i].cpu_burst;
						process[i].device=0;
						process[i].d2=-1;

					}
					sort(process,process+n,com);
						for(i=0;i<n;i++)
						{
							tem[i]=process[i].cpu_burst;
							check[i]=0;
						}
					clock=0;
					i=0;
					terminated;
					while(terminated!=n)
					{
						flag=0;
						z=0;
						for(x=0;x<terminated;x++)
						{
							if(kill[x].compare(process[i].name)==0)
								flag=1;
						}
						if(flag==0&&process[i].device==0)
						{
							cout<<process[i].name<<" is executing in cpu"<<'\n';
							if(check[i]==0)
							{
								process[i].response=clock-process[i].arr;
								check[i]=1;
							}
							if(process[i].burst_time<qua)
							{
								clock+=process[i].burst_time;
								process[i].burst_time=0;
							}
							else
							{
								clock+=qua;
								process[i].burst_time-=qua;
							}
							if(process[i].burst_time==0)
							{
								process[i].cpu_burst--;
								if(process[i].cpu_burst!=0)
								{
									cout<<process[i].name<<" device queue"<<'\n';
									process[i].device=1;
									process[i].d2=clock+bt;
								}
								process[i].burst_time=bt;
							}
							if(process[i].cpu_burst==0)
							{
								process[i].exit=clock;
								kill[terminated]=process[i].name;
								terminated++;
								cout<<process[i].name<<" Terminated"<<'\n';
							}
							for(int y=0;y<n;y++)
							{
								if(clock==process[y].d2)
									process[y].device=0;
							}
						}
						else
						{
							clock++;
							for(int y=0;y<n;y++)
							{
								if(clock==process[y].d2)
									process[y].device=0;
							}
						}
						i=(i+1)%n;
					}

					at=0;
					aw=0;
					ar=0;
					for(i=0;i<n;i++)
					{
						cout<<process[i].name<<'\n';
						cout<<"Arrival time :"<<process[i].arr<<'\n';
						cout<<"Exit time :"<<process[i].exit<<'\n';
						at+=process[i].exit-process[i].arr;
						cout<<"TAT :"<<process[i].exit-process[i].arr<<'\n';
						aw+=(process[i].exit-process[i].arr)-(tem[i]*bt+(tem[i]-1)*bt);
							
						ar+=process[i].response;

						cout<<"WT :"<<(process[i].exit-process[i].arr)-(tem[i]*bt+(tem
									[i]-1)*bt)<<'\n';
						cout<<"RT :"<<process[i].response<<'\n';
					}
					cout<<"AT :"<<at/n<<'\n';
					cout<<"AW :"<<aw/n<<'\n';
					cout<<"AR :"<<ar/n<<'\n';












					break;
					default:
					cout<<"error"<<'\n';
				}

				return 0;
			}
