#include<stdio.h>

struct q2
{
	int burst;
    int priority,waiting_t,turn_a_t;
    int arrival_time;

};
int main()
{
	int n;
	printf("Enter Total Number of Process:");
    scanf("%d",&n);
    
     printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&burst[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        priority[i]=i+1;           //contains process number
    }
 
}