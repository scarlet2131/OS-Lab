#include<bits/stdc++.h>
using namespace std;
int minIndex(queue<int> &q, int sortedIndex) 
{ 
    int min_index = -1; 
    int min_val = INT_MAX; 
    int n = q.size(); 
    for (int i=0; i<n; i++) 
    { 
        int curr = q.front(); 
        q.pop();  // This is dequeue() in C++ STL 
  
        // we add the condition i <= sortedIndex 
        // because we don't want to traverse 
        // on the sorted part of the queue, 
        // which is the right part. 
        if (curr <= min_val && i <= sortedIndex) 
        { 
            min_index = i; 
            min_val = curr; 
        } 
        q.push(curr);  // This is enqueue() in  
                       // C++ STL 
    } 
    return min_index; 
} 
  
// Moves given minimum element to rear of  
// queue 
void insertMinToRear(queue<int> &q, int min_index) 
{ 
    int min_val; 
    int n = q.size(); 
    for (int i = 0; i < n; i++) 
    { 
        int curr = q.front(); 
        q.pop(); 
        if (i != min_index) 
            q.push(curr); 
        else
            min_val = curr; 
    } 
    q.push(min_val); 
} 
  
void sortQueue(queue<int> &q) 
{ 
    for (int i = 1; i <= q.size(); i++) 
    { 
        int min_index = minIndex(q, q.size() - i); 
        insertMinToRear(q, min_index); 
    } 
} 
int main()
{
	cout<<"systemwise input:"<<endl;
	int num_c,d_rate,p_n;
	cin>>num_c>>d_rate>>p_n;
	
	int arr;
	int v[p_n];
	cout<<"Process wise input:"<<endl;
	for(int i=0;i<p_n;i++)
	{
		cin>>arr;
		v[i]=arr;
	}
	sort(v,v+p_n);
	int n_io;
	vector<pair<int,pair<int,int> > >v1;
	vector<pair<int,int> >v2;
	pair<int,int> p;
	int n_cy,d_s;
	pair<int,int> p1;

	for(int i=0;i<p_n;i++)
	{
		cin>>n_io;
		for(int j=0;j<n_io;j++)
		{
			cin>>n_cy>>d_s;
			p=make_pair(n_cy,d_s);
			v1.push_back(make_pair(j,p));
		}
		int d_cpu;
		
		for(int j=0;j<n_io+1;j++)
		{
			
			cin>>d_cpu;
			

			v2.push_back(make_pair(j,d_cpu));
		}
	}
	queue <int> cpu;
	queue <int> io;

	for(int i=0;i<v1.size();i++)
	{
		cout<<v1[i].first<<" "<<v1[i].second.first<<" "<<v1[i].second.second<<endl;
	}
	for(int i=0;i<v2.size();i++)
	{
		cout<<v2[i].first<<" "<<v2[i].second<<endl;
	}
	int exec[p_n];
	int k=0;
	int c=0;
	while(c<p_n)
	{
		for(int i=0;i<v1.size();i++)
		{
			if(v1[i].first==c)
			{
				cpu.push(v1[i].second.second);
			}
			sortQueue(cpu);
			
			c++;


		}
	}
	for(int j=0;j<cpu.size();j++)
		{
			cout<<cpu.front()<<" ";
			
		}
		cout<<endl;





}