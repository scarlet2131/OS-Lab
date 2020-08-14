#include<bits/stdc++.h>
using namespace std;
class pcb
{   public:
	string text;
	int timelimit;
	string data;
	int ns;
	stack<int> stack_;
	int nh;
	vector<int> heap_;
	string state;
	int priority;
    int nh2;
    void save_results()
    {   int st,he;
    	cout<<"enter text:"<<endl;
    	cin>>text;
    	cout<<"enter timelimit:"<<endl;
    	cin>>ws>>timelimit;
    	cout<<"enter data:"<<endl;
    	cin>>ws>>data;
    	cout<<"number of elements in stack:"<<endl;
    	cin>>ws>>ns;
    	while(ns>0)
    	{	
    		cin>>st;
    	    stack_.push(st);
    	    ns--;
    	}
    	cout<<"number of elements in heap:"<<endl;
    	cin>>nh;
        nh2=nh;
    	while(nh>0)
    	{	
    		cin>>he;
    	    heap_.push_back(he);
    	    make_heap(heap_.begin(),heap_.end());
    	    nh--;
    	}

    	cout<<"enter state:"<<endl;
    	cin>>ws>>state;
    	cout<<"enter priority:"<<endl;
    	cin>>ws>>priority;
    }
    void get_results()
    {
    	cout<<"Text: "<< text<<endl;
    	cout<<"timelimit: "<<timelimit<<endl;
    	cout<<"Data: "<< data<<endl;
    	cout<<"elements of stack: "<<endl;
    	while(!stack_.empty())
    	{
           cout<<stack_.top()<<" ";
           stack_.pop();
    	}
        cout<<endl;
    	cout<<"elements of heap: "<<endl;
    	for(int i=0;i<nh2;i++)
    	{
          cout<<heap_[i]<<" ";
          cout<<endl;
    	}
    	cout<<"state: "<<state<<endl;
        cout<<"priority: "<<priority<<endl;
    }
};

bool operator<(const pcb& prior1,const pcb&prior2)
{
    return prior1.priority<prior2.priority;
}   
int main()
{
    cout<<"enter number of processes"<<endl;
    int n;
    cin>>n;
	pcb obj[n];
    for(int i=0;i<n;i++)
    {
        obj[i].save_results();
    }
	priority_queue<pcb> job;
    queue<pcb> ready,device;
    for(int i=0;i<n;i++)
    {
        job.push(obj[i]);
    }
    cout<<"printing processes in job queue"<<endl;
    while(!job.empty())
    {
        pcb o=job.top();
        ready.push(o);
        device.push(o);
        job.pop();
        o.get_results();
    }
    cout<<"printing processes in ready queue"<<endl;
    while(!ready.empty())
    {
        pcb o1=ready.front();
        ready.pop();
        o1.get_results();
        pcb o2=device.front();
        device.pop();
        o2.get_results();
    }
return 0;
}


