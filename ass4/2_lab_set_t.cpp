#include<bits/stdc++.h>
using namespace std;
int n;
int a;
int ans;
bool lock=false;
bool testandset(bool *target)
{
	bool rv=*target;
	*target=true;
	return rv;
}

	
void *Th1(void *)
		{
			do{
	
				while(testandset(&lock));
			
			cout<<"CS1 n "<<endl;
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
				    lock=false;
					cout<<a<<" ";

					
				}


			}
			

			cout<<endl;
		}while(true);
		

	}
void *Th2(void * )
			{

				cout << "second "<<endl;
		
				//do{
				while(testandset(&lock));
					//cout<< "cs 2"<<endl;
				//lock(s);
			 		
					ans=(float)n/a;
					lock=false;	
					cout<<"ans "<<ans<<" ";
				

				
				cout<<endl;
				
				//unlock(s);
				//}while (true);
		
				
			}
			
		


int main()
{
	pthread_t tid,t1;
	
	pthread_create(&tid,NULL,Th1,NULL);
	
	pthread_create(&t1,NULL,Th2,NULL);
	pthread_join(tid,NULL);
	pthread_join(t1,NULL);
	pthread_exit(NULL);
	return 0;
}