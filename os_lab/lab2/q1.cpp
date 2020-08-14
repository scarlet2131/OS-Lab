#include<bits/stdc++.h>
#include<stdio.h> // for normal IO and perror()
#include<sys/types.h> // for data type pid_t
#include<sys/wait.h> // for wait() system call
#include<unistd.h>	// for fork(), exit() system call and NULL
#include<stdlib.h> // for abort()
using namespace std;

/*int fib(int n,int a[],int k) 
{ 
	
    if (n <= 1) 
    {
       a[k++]=n; 
    }
   else
   {
    a[k++]= fib(n-1) + fib(n-2);
    }
   return a;
} */

int main()
    { 
    	int n;
    	cin>>n;
		int a[n];
		int k=2;
		int next=0;
    	int l1=0,l2=1;
    	int fd[2],i=0;
	    pipe(fd);
		pid_t pid;
	     
		pid = fork();
		if (pid < 0) 
	        {
	         perror("fork"); 		
	         abort(); 
		   }	
		else if(pid == 0) 
	 	   {
			printf("I am in child process\n");
			
			//fib(n,a,k);
			
			
			next=l1+l2;
			a[0]=0;
			a[1]=1;
			i=2;
			while(i<=n)
				{
					a[k++]=next;
					
					l1=l2;
					l2=next;

					next=l1+l2;
					i++;

				
			}
			close(fd[0]);
			close(1);
			dup(fd[1]);


			 write(fd[1],a,sizeof(a));

			
			 
			return 0;	
		   }
		else 
		   {

		  
	      	printf("I am in parent\n");
			wait(NULL);
			close(0);
		   close(fd[1]);
		   dup(fd[0]);
		   int l=read(fd[0],a,sizeof(a));	


		  for(int i=0;i<l/4;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;	
			
			printf("child terminated");
		   }
		return 0;
	}
