#include<bits/stdc++.h>
using namespace std;
int a;
//int ans=0;
//int k=0;

int n;
int turn;
Boolean flag[2];


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
			do
			{
				flag[l]=TRUE;
				turn=m;
				while(flag[m]&& turn==m);
					a=l;
					cout<<a<<" ";
				flag[l]=FALSE;
			}while(TRUE);
			
			
		}
	}
	cout<<endl;
	
		
		

		
}
void *Th2(void *)
{
	
	
 

		cout<<(float)n/a<<" ";


	
	cout<<endl;
	
	

	
}
int main()
{
	pthread_t tid,t1;
	//lock_init();
	pthread_create(&tid,NULL,Th1,NULL);
	pthread_create(&t1,NULL,Th2,NULL);
	pthread_join(tid,NULL);
	pthread_join(t1,NULL);
	pthread_exit(NULL);
	return 0;
}