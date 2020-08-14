#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct pcb
{
	int burst,arr,priority,kill,times,response,exit;
	string name;
};
typedef struct pcb pcb;
bool com(pcb a,pcb b)
{
	return (a.arr<=b.arr);
}
int main()
{
pcb process[100];
int t,i,terminated,n,clock,count;
cout<<"Enter quantum time"<<'\n';
cin>>t;
pcb ready[100];
pcb p1[100],p2[100],p3[100],p4[100],p5[100];
int c1,c2,c3,c4,c5,i1,i2,i3,i4,i5;
c1=0;
c2=0;
c3=0;
c4=0;
c5=0;
i1=0;
i2=0;
i3=0;
i4=0;
i5=0;
pcb run;
string done[100];
cout<<"Enter number of processes"<<'\n';
cin>>n;
for(i=0;i<n;i++)
{
cout<<"Enter name"<<'\n';
cin>>process[i].name;
cout<<"Enter arrival time"<<'\n';
cin>>process[i].arr;
cout<<"Enter burst time"<<'\n';
cin>>process[i].burst;
cout<<"Enter priority for entry into which queue"<<'\n';
cin>>process[i].priority;
process[i].response=-1;
process[i].kill=0;
process[i].times=0;
}
sort(process,process+n,com);
terminated=0;
clock=0;
i=0;
int t1=0;
int t2=0;
int t3=0;
int t4=0;
int t5=0;
int j;
while(terminated!=n)
{
	count=0;
for(i=0;i<n;i++)
{
	//if(process[i].name.compare("p1")==0)
	//	cout<<process[i].kill;
	int z=0;
	for(j=0;j<terminated;j++)
	{
		if(done[j].compare(process[i].name)==0)
			z=1;
	}
	if(process[i].arr<=clock&&process[i].kill==0&&z==0&&process[i].burst!=0)
	{
		if(process[i].priority==1)
		p1[c1++]=process[i];
		else if(process[i].priority==2)
		p2[c2++]=process[i];
		else if(process[i].priority==3)
		p3[c3++]=process[i];
		else if(process[i].priority==4)
		p4[c4++]=process[i];
		else
			p5[c5++]=process[i];
	}	
}
if(c1!=0)
{
	//t1++;
	run=p1[i1];
	for(j=0;j<n;j++)
	{
		if(run.name.compare(process[j].name)==0)
			break;
	}
	process[j].times++;
	if(process[j].response<0)
	process[j].response=clock;	
	cout<<process[j].name<<" is executing in cpu"<<'\n';
	if(process[j].burst>t)
	{
		process[j].burst-=t;
		clock+=t;
		if(process[j].times==2||t1==2)
		{
			process[j].priority=2;
			cout<<process[j].name<<" has arrived at q2 time= "<<clock<<'\n';
			process[j].times=0;
		}
	}
	else
	{
		clock+=process[j].burst;
		process[j].exit=clock;
		process[j].burst=0;
		process[j].kill=1;
		done[terminated]=process[j].name;
		terminated++;
		

		//if(run.name.compare("p1")==0)
		//cout<<run.kill;	
		//cout<<c1;
	}
	c1--;
	if(c1!=0)
	i1=(i1+1)%c1;
}
else if(c2!=0)
{
	run=p2[i2];
	for(j=0;j<n;j++)
	{
		if(run.name.compare(process[j].name)==0)
		{
			
			break;
		}
	}
	process[j].times++;
	if(process[j].response<0)
	process[j].response=clock;	
	/*for(int j=0;j<n;j++)
	{
		if(run.name.compare(process[j].name)==0)
		cout<<process[j].times;
	}*/	
	//t2++;
	//cout<<t2;
	cout<<run.name<<" is executing in cpu"<<'\n';
	if(process[j].burst>t)
	{
		process[j].burst-=t;
		clock+=t;
		if(process[j].times==2||t2==2)
		{
			process[j].priority=3;
			cout<<process[j].name<<" has arrived at q3 time= "<<clock<<'\n';
			process[j].times==0;
		}
	}
	else
	{
		clock+=process[j].burst;
		process[j].exit=clock;
		process[j].burst=0;
		process[j].kill=1;
		done[terminated]=process[j].name;
		terminated++;
		
	}
	c2--;
	if(c2!=0)
	i2=(i2+1)%c2;
}
else if(c3!=0)
{
//t3++;
//cout<<"we";
	run=p3[i3];
	for(j=0;j<n;j++)
	{
		if(run.name.compare(process[j].name)==0)
			break;
	}
	process[j].times++;
	if(process[j].response<0)
	process[j].response=clock;	
	cout<<process[j].name<<" is executing in cpu"<<'\n';
	if(process[j].burst>t)
	{
		process[j].burst-=t;
		clock+=t;
		if(process[j].times==2||t3==2)
		{
			process[j].priority=4;
			cout<<process[j].name<<" has arrived at q4 time= "<<clock<<'\n';
			process[j].times==0;
		}
	}
	else
	{
		clock+=process[j].burst;
		process[j].exit=clock;
		process[j].burst=0;
		process[j].kill=1;
		done[terminated]=process[j].name;
		terminated++;
		
	}
	c3--;
	if(c3!=0)
	i3=(i3+1)%c3;
}
else if(c4!=0)
{
	//t4++;
	run=p4[i4];
	for(j=0;j<n;j++)
	{
		if(run.name.compare(process[j].name)==0)
                 break;
	}
	process[j].times++;
	if(process[j].response<0)
		process[j].response=clock;
	cout<<process[j].name<<" is executing in cpu"<<'\n';
	if(process[j].burst>t)
	{
		process[j].burst-=t;
		clock+=t;
		if(process[j].times==2||t4==2)
		{
			process[j].priority=5;
			cout<<process[j].name<<" has arrived at q5 time= "<<clock<<'\n';
			process[j].times==0;
		}
	}
	else
	{
		clock+=process[j].burst;
		process[j].exit=clock;
		process[j].burst=0;
		process[j].kill=1;
		done[terminated]=process[j].name;
		terminated++;
		
	}
	c4--;
	if(c4!=0)
	i4=(i4+1)%c4;
}
else
{
	//cout<<"he";
	run=p5[i5];
	for(j=0;j<n;j++)
	{
	if(run.name.compare(process[j].name)==0)
	break;
	}
if(process[j].response<0)
process[j].response=clock;	
	cout<<process[j].name<<" is executing in cpu"<<'\n';
	clock+=process[j].burst;
	process[j].exit=clock;
	process[j].burst=0;
	process[j].kill=1;
	done[terminated]=process[j].name;
	terminated++;
	c5--;
	i5++;
}
}
int at=0;
int ar=0;
int aw=0;
for(i=0;i<n;i++)
{
	cout<<process[i].name<<'\n';
	ar+=process[i].response;
	cout<<"RT "<<abs(process[i].response)<<'\n';
	at+=(process[i].exit-process[i].arr);
	cout<<"TAT "<<abs(process[i].exit-process[i].arr)<<'\n';
	aw+=((process[i].exit-process[i].arr)-process[i].burst);
	cout<<"WT "<<abs((process[i].exit-process[i].arr)-process[i].burst)<<'\n';
}
cout<<"Avg response "<<abs(ar/n)<<'\n';
cout<<"Avg turn around time "<<abs(at/n)<<'\n';
cout<<"Avg waiting time"<<abs(aw/n)<<'\n';
return 0;
}

