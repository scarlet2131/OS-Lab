#include<bits/stdc++.h>
#include<pthread.h>
#include<unistd.h>
using namespace std;
bool lock=false;
int i=2,n;
bool isprime(int l)
{
	int count=0;
	if(l==2)
		return true;
	for(int j=2;j<l;j++)
	{
		if(l%j==0)
			count++;
	}
	if(count>=1)
		return false;
}
void Swap (bool *a, bool *b)

{

	bool temp = *a;

	*a = *b;

	*b = temp;

}

void* thread1(void *)
{
	//bool lock=false;
	do{

		bool key=true;
		while(key==true)
			swap(&key,&lock);
		if(isprime(i))
		{
			cout<<i<<" ";
		}
		lock=false;
	}while(true);
}
void * thread2(void *){
	//bool lock = false;
	do{
		bool key=true;
		while(key==true)
			swap(&key,&lock);
		if(isprime(i))
		{
			double res= (n*1.0)/i;
			cout<<res<<endl;
		}
	}while(true);
}

int main()
{
	//bool lock=false;
   cout<<"in"<<endl;
	pthread_t p1;
	pthread_t p2;
	cin>>n;
	for(int k=0;k<n;k++)
	{
		pthread_create(&p1,NULL,thread1,NULL);
		pthread_join(p1,NULL);
		pthread_create(&p2,NULL,thread2,NULL);
	}
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);


	pthread_exit(NULL);
}




