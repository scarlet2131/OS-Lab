#include<stdio.h>

 

int main()
{
    int burst[20];
    
    int priority[20],waiting_t[20],turn_a_t[20];
    int pr[20],arrival_time[20],j,i,n;
    int total=0,pos,temp,avg_wt,avg_tat;
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
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
 
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;
    }
 
    waiting_t[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting_t[i]=0;
        for(j=0;j<i;j++)
            waiting_t[i]+=burst[j];
 
        total+=waiting_t[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turn_a_t[i]=burst[i]+waiting_t[i];     //calculate turnaround time
        total+=turn_a_t[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",priority[i],burst[i],waiting_t[i],turn_a_t[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
	return 0;
}
