#include<bits/stdc++.h>
using namespace std;
int a;
//int ans=0;
//int k=0;

int n;
int turn;
int flag[2];

void lock_init()
{
	flag[0]=0;
	flag[1]=0;
	turn=0;
}
void lock(int s)
{
	
	flag[s]=1;
	turn=1-s;
	while(flag[1-s]==1 && turn==1-s);
}
void unlock(int s)
{
	flag[s]=0;
}

void *Th1(void *s1)
{
	int s=0;
	s1=&s;
	
	cin>>n;
	int f=0;
	
	for(int i=2;i<=n;i++)
	{
		f=0;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				f=1;
			}
		}
		if(f==0)
		{
			lock(s);
			a=i;
			cout<<a<<" ";
			
		}
	}
	cout<<endl;
	
		
		

		
}
void *Th2(void * s1)
{
	int s=0;
	s1=&s;
	//lock(s);
 

		cout<<(float)n/a<<" ";


	
	cout<<endl;
	//unlock(s);
	

	
}
int main()
{
	pthread_t tid,t1;
	lock_init();
	pthread_create(&tid,NULL,Th1,NULL);
	
	pthread_create(&t1,NULL,Th2,NULL);
		
		pthread_join(tid,NULL);
		pthread_join(t1,NULL);
	
	
	
	pthread_exit(NULL);
	return 0;
}