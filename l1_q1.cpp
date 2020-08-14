#include<bits/stdc++.h>
using namespace std;
struct PCB
{
	string text;
	long int data;
	stack<int> s;
	long int heap;
	//string state;
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
	
	struct PCB PCB[1000];
	//int i;
	string state;
	int t=0;
	while(1)
	{
		int x;
		int c;
		cin>>x;
		if(x==1)
		{
			cout<<"Enter all details:"<<endl;
			cout<<"enter text:";
			cin>>PCB[t].text;
			cout<<"enter data:";
			cin>>PCB[t].data;
			cout<<"enter stack:";
			for(int j=0;j<5;j++)
			{
				cin>>c;
				PCB[j].s.push(c);

			}
			cout<<"heap:";
			cin>>PCB[t].heap;
			state="save";
			cout<<"priority:";
			cin>>PCB[t].priority;
			t++;
			cout<<endl;

		}
		else if(x==2)
		{
			cout<<"reload all details:"<<endl;
			sort(PCB,PCB+t,compareTwopcb);
			for(int i=0;i<t;i++)
			{
				cout<<"text:"<<" ";
				cout<<PCB[i].text<<endl;
				cout<<"data:"<<" ";
				cout<<PCB[i].data<<endl;
				cout<<"stack:"<<" ";
				for(int j=4;j>=0;j--)
				{
					cout<<PCB[j].s.top()<<endl;
					PCB[j].s.pop();
				}
				
				cout<<"heap:"<<" ";
				cout<<PCB[i].heap<<endl;
				cout<<"State"<<" ";
				cout<<"reload"<<endl;
				cout<<"priority:"<<" ";
				cout<<PCB[i].priority<<endl;
			}
		}
		else if(x==3)
		{
			break;
		}
}
	
}