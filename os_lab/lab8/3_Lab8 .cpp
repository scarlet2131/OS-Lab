#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b)
{
	return __gcd(a,b);
}
int main()
{
	int m,working_set[100][100],n,size[100],i,t_size,a,b,j;
	int k,tlb_reach[100];
	cout<<"Enter n"<<'\n';
	cin>>n;
	cout<<"Enter m"<<'\n';
	cin>>m;
	k=0;
	while(m--)
	{
		cout<<"Enter TLB size"<<'\n';
		cin>>t_size;
		for(i=0;i<n;i++)
		{
			cout<<"Enter total size of process and data structure "<<i<<'\n';
			cin>>size[i];	
		}
		a=size[0];
		b=size[1];
		int r=gcd(a,b);
		for(i=2;i<n;i++)
			r=gcd(r,size[i]);
		cout<<"Optimum value of page size :"<<r<<'\n';
		int internal_fragmentation=0;
		for(i=0;i<n;i++)
		{
			if(size[i]%r!=0)
				internal_fragmentation+=(r-size[i]%r);
		}
		cout<<"Internal Fragmnetation: "<<internal_fragmentation<<'\n';
		tlb_reach[k++]=t_size*r;
		cout<<"TLB REACH :"<<(t_size*r)<<'\n';
	}
	double sum=0,avg;
	for(i=0;i<k;i++)
		sum+=tlb_reach[i];
	avg=(double)sum/(double)k;
	cout<<"Average optimum value of TLB reach :"<<avg<<'\n';
	return 0;
}

