#include<bits/stdc++.h>
using namespace std;
int a;
//int ans=0;
//int k=0;

int n;


void *Th1(void *)
{
	
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
			
			a=i;
			cout<<a<<" ";
			
		}
	}
	cout<<endl;
	
		
		

		
}
void *Th2(void * )
{
	
 

		cout<<(float)n/a<<" ";


	
	cout<<endl;
	//unlock(s);
	

	
}
int main()
{
	pthread_t tid,t1;
	
	pthread_create(&tid,NULL,Th1,NULL);
	pthread_join(tid,NULL);
	pthread_create(&t1,NULL,Th2,NULL);


		
		
		
	
	
	
	pthread_exit(NULL);
	return 0;
}