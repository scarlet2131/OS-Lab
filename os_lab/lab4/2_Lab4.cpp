#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

using namespace std;
int n, lock=0, i=2, flag[2], turn, key=0;
sem_t mutex;
bool checkPrime(int n)
{
	int i,count=0;
	if(n==2)
		return true;
	for(i=2; i<n; i++)
		if(n%i==0)
			count++;
	if(count>=1)
		return false;
}
void *thread1(void *vargp)
{
	while(i<n)
	{
		while(lock!=0)	{}
		if(checkPrime(i))
		{
			cout<<i<<" ";
			//lock=1;
		}
		lock=1;
		//i++;
	}
}	
void lock_init()
{
	flag[0]=flag[1]=0;
	turn = 0;
}
void *thread2(void *vargp)
{
	while(i<n) {
		while(lock!=1)	{}
		if(checkPrime(i))
		{
			//lock=0;
			double res = (n*1.0)/i;
			cout<<res<<endl;
		}
		lock=0;
		i++;
	}
}
void *thread3(void *vargp)
{
	while(i<n)
	{	
		flag[0]=1;
		turn=1;
		while(flag[turn]==1 && 1==turn){}
		if(checkPrime(i))
		{
			//cout<<i<<" ";
		}
		flag[0]=0;
	}
}
void *thread4(void *vargp)
{
	while(i<n) {
		flag[1]=1;
		turn=0;
		while(flag[turn]==1 && 0==turn){}
		if(checkPrime(i))
		{
			double res = (n*1.0)/i;
			cout<<i<<" "<<res<<endl;
		}
		flag[1]=0;
		i++;
	}
}
void *thread5(void *vargp)
{
	while(i<n)
	{
		key=1;
		while(key==1)
			swap(key, lock);
		//if(checkPrime(i))
			//cout<<i<<" ";
		lock=0;
	}
}
void *thread6(void *vargp)
{
	while(i<n)
	{
		key=0;
		while(key==0)
			swap(key, lock);
		if(checkPrime(i))
		{
			double res = (n*1.0)/i;
			cout<<i<<" "<<res<<endl;
		}
		i++;
		lock=0;
		//cout<<"in thread6"<<endl;
	}
}
void wait(int *s)
{
	while(*s <= 0){}
	*s --;
}
void signal(int *s)
{
	*s ++;
}
void *thread7(void *vargp)
{
	while(i<n)
	{
		sem_wait(&mutex);
		if(checkPrime(i)){
			//cout<<i<<" ";
}
		sem_post(&mutex);
	}
}
void *thread8(void *vargp)
{
	while(i<n)
	{
		sem_wait(&mutex);
		if(checkPrime(i))
		{
			double res = (n*1.0)/i;
			cout<<i<<" "<<res<<endl;
		}
		i++;
		sem_post(&mutex);
	}
}
int main()
{
	pthread_t tid1, tid2, tid3, tid4, tid5, tid6, tid7, tid8;
	cin>>n;
	cout<<"Test and Set Algorithm"<<endl;
	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	cout<<"Peterson's Algo:"<<endl;
	i=2;
	lock_init();
	pthread_create(&tid3, NULL, thread3, NULL);
	pthread_create(&tid4, NULL, thread4, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);

	cout<<"Using Swap Function:"<<endl;
	i=2, lock=0;
	pthread_create(&tid5, NULL, thread5, NULL);
	pthread_create(&tid6, NULL, thread6, NULL);
	pthread_join(tid5, NULL);
	pthread_join(tid6, NULL);
	//pthread_exit(NULL);

	cout<<"Using Semaphore Function: "<<endl;	
	i=2;
	sem_init(&mutex, 0, 1);
	pthread_create(&tid7, NULL, thread7, NULL);
	pthread_create(&tid8, NULL, thread8, NULL);
	pthread_join(tid7, NULL);
	pthread_join(tid8, NULL);
	pthread_exit(NULL);
	return 0;
}

