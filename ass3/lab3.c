#include<stdio.h>

struct q2
{
	int burst;
    int priority,waiting_t,turn_a_t;
    int arrival_time;
    int pr;

};
int main()
{
	int total=0,pos,temp,avg_wt,avg_tat;
	int j,n,i;
	struct q2 rem[100];

	printf("Enter Total Number of Process:");
    scanf("%d",&n);

     printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&q2.burst[i]);
        printf("Priority:");
        scanf("%d",&q2.pr[i]);
        q2.priority[i]=i+1; 
        printf("Arrival time:");
        scanf("%d",&q2.arrival_time[i]);   
               //contains process number
    }
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(q2.pr[j]<q2.pr[pos])
                pos=j;
        }
 
        temp=q2.pr[i];
        q2.pr[i]=q2.pr[pos];
        q2.pr[pos]=temp;
 
        temp=q2.burst[i];
        q2.burst[i]=q2.burst[pos];
        q2.burst[pos]=temp;
 
        temp=q2.priority[i];
        q2.priority[i]=q2.priority[pos];
        q2.priority[pos]=temp;
    }
     q2.qwaiting_t[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        q2.waiting_t[i]=0;
        for(j=0;j<i;j++)
           q2.qwaiting_t[i]+=q2.burst[j];
 
        total+=q2.waiting_t[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        q2.qturn_a_t[i]=q2.qburst[i]+waiting_t[i];     //calculate turnaround time
        total+=q2.turn_a_t[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",q2.priority[i],q2.burst[i],q2.waiting_t[i],q2.turn_a_t[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
	return 0;

 
}