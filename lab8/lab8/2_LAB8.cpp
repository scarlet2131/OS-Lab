#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<sys/ipc.h>
#include<semaphore.h>

using namespace std;
int M=0;
void * A(void * )
{
	M=M+50;
}
void *B(void *)
{
	M=M+50;
} 
void *C(void *)
{
	M=M+50;
} 
void *D(void *)
{
	M=M-75;
} 
void *E(void *)
{
	M=M-75;
}
double standard_deviation(int a[], int n) 
{ 
    // Compute mean (average of elements) 
    int sum = 0; 
    for (int i = 0; i < n; i++) 
        sum += a[i]; 
    double mean = (double)sum /  
                  (double)n; 
  
    // Compute sum squared  
    // differences with mean. 
    double sqDiff = 0; 
    for (int i = 0; i < n; i++)  
        sqDiff += (a[i] - mean) *  
                  (a[i] - mean); 
    return sqrt(sqDiff / n); 
} 
  


int main()
{
	int n;
	cin>>n;
	int j=0;
	int arr[n];
	pthread_t t1,t2,t3,t4,t5;
	for(int i=0;i<n;i++)
	{
		pthread_create(&t1,NULL,A,NULL);
		pthread_create(&t2,NULL,B,NULL);
		pthread_create(&t3,NULL,C,NULL);
		pthread_create(&t4,NULL,D,NULL);
		pthread_create(&t5,NULL,E,NULL);
		arr[j++]=M;
			M=0;
	}
	float x=0,y=0;
	
	for(int i=0;i<j;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	//mean
	int sum=0;
			for(int i=0;i<n;i++)
			  {
			  sum=sum+arr[i];
			  }
		 			x=(float)sum/(float)n;
		 			cout<<"MEAN:"<<" "<<x<<endl;
	//median
 			for(int i=0;i<n;i++)
			  {
			  for(int j=i+1;j<n;j++)
			   {
			   if(arr[i]>arr[j])
			    {
			    int t=arr[i];
			    arr[i]=arr[j];
			    arr[j]=t;
			    }
			   }
			  }
			 if(n%2==0)
			 y=(float)(arr[n/2]+arr[(n-1)/2])/2;
			 else
			 y=arr[(n-1)/2];
			cout<<"MEDIAN:"<<" "<<y<<endl;


			//mode
			int c=0,max=0;
			int mode;
			int k=0;
			int b[20]={0};

			for(int i=0;i<n-1;i++)
			  {
			  mode=0;
			  for(int j=i+1;j<n;j++)
			   {
			   if(arr[i]==arr[j])
			    {
			    mode++;
			    }
			   }
			  if((mode>max)&&(mode!=0))
			   {
			   k=0;
			   max=mode;
			   b[k]=arr[i];
			   k++;
			   }
			  else if(mode==max)
			   {
			   b[k]=arr[i];
			   k++;
			   }
			  }
			 for(int i=0;i<n;i++)
			  {
			  if(arr[i]==b[i])
			  c++;
			  }
			 if(c==n)
			 {
			 	printf("\nThere is no mode");
			 	
			 }
			 
			 else
			  {
			  printf("\nMode\t= ");
			  for(int i=0;i<k;i++)
 					cout<<b[i]<<" ";
			 
			  }
			  cout<<endl;


			  //standard deviation

			  cout<<"Standard deviation"<<" "<<standard_deviation(arr,n)<<endl;
 }
	

