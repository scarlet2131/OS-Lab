#include<bits/stdc++.h>
using namespace std;

struct PCB
{
	int processID;
	string state;
	int priority;
	

	
};
bool compareTwopcb(PCB a, PCB b) 
{ 
    // If total marks are not same then 
    // returns true for higher total 
    if (a.priority != b.priority ) 
        return a.priority > b.priority; 
  
    // If marks in Maths are not same then 
    // returns true for higher marks 
    
} 
int main()
{
	queue<PCB> JQ;
	queue<PCB> RQ;
	queue<PCB> DQ;

	struct PCB PCB[1000];
	int t=0,t1=0,t2=0;
	cout<<"Enter 1 for details:";
	int x;
	int x1;
	while(1)
	{
		cin>>x;
		if(x==1)
		{
			cin>>PCB[t].processID;
			cin>>PCB[t].state;
			cin>>PCB[t].priority;
			PCB[t].JQ.push(PCB[t].processID);
			PCB[t].JQ.push(PCB[t].state);
			PCB[t].JQ.push(PCB[t].priority);
			t++;
			if(state=="io")
			{
				PCB[t].DQ.push(PCB[t].processID);
				PCB[t].DQ.push(PCB[t].state);
				PCB[t].DQ.push(PCB[t].priority);
				t++;
			}
			else 
			{
				PCB[t].RQ.push(PCB[t].processID);
				PCB[t].RQ.push(PCB[t].state);
				PCB[t].RQ.push(PCB[t].priority);
				t++;
			}
			cin>>x1;
			if(x1==1)
			{
				sort(PCB,PCB+t,compareTwopcb);
				cout<<"print JOB QUEUE:";
				for(int i=0;JQ.size();i++)
				{
					cout<<PCB[i].JQ.front()<<" ";
				JQ.pop();	
				}
				
			}


		}
		else 
		{
			break;
		}
	}
}