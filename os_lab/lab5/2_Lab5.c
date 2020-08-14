#include<stdio.h>

 
int compltedPhilo = 0,i;
 
struct Forks{
	int taken;
};
 
struct Philosphers{
	int l_hand;
	int r_hand;
};
 
void dining(int p,struct Forks f[],struct Philosphers P[],int n){
	if(P[p].l_hand==10 && P[p].r_hand==10)
        printf("Philosopher %d completed his dinner\n",p+1);
	else if(P[p].l_hand==1 && P[p].r_hand==1){
            printf("Philosopher %d completed his dinner\n",p+1);
 
            P[p].l_hand = P[p].r_hand = 10;
            int otherFork = p-1;
 
            if(otherFork== -1)
                otherFork=(n-1);
 
            f[p].taken = f[otherFork].taken = 0;
            printf("Philosopher %d released Forks %d and Forks %d\n",p+1,p+1,otherFork+1);
            compltedPhilo++;
        }
        else if(P[p].l_hand==1 && P[p].r_hand==0){
                if(p==(n-1)){
                    if(f[p].taken==0){
                        f[p].taken = P[p].r_hand = 1;
                        printf("Fork %d taken by philosopher %d\n",p+1,p+1);
                    }else{
                        printf("Philosopher %d is thinking for Forks %d\n",p+1,p+1);
                    }
                }else{
                    int dupphilID = p;
                    p-=1;
 
                    if(p== -1)
                        p=(n-1);
 
                    if(f[p].taken == 0){
                        f[p].taken = P[dupphilID].r_hand = 1;
                        printf("Fork %d taken by Philosopher %d\n",p+1,dupphilID+1);
                    }else{
                        printf("Philosopher %d is thinking for Fork %d\n",dupphilID+1,p+1);
                    }
                }
            }
            else if(P[p].l_hand==0){
                    if(p==(n-1)){
                        if(f[p-1].taken==0){
                            f[p-1].taken = P[p].l_hand = 1;
                            printf("Fork %d taken by philosopher %d\n",p,p+1);
                        }else{
                            printf("Philosopher %d is thinking for Forks %d\n",p+1,p);
                        }
                    }else{
                        if(f[p].taken == 0){
                            f[p].taken = P[p].l_hand = 1;
                            printf("Fork %d taken by Philosopher %d\n",p+1,p+1);
                        }else{
                            printf("Philosopher %d is thinking for Fork %d\n",p+1,p+1);
                        }
                    }
        }else{}
}
 
int main(){
	printf("Enter no of philosphers :");
	int n;
	scanf("%d",&n);
	struct Forks f[n];
	struct Philosphers P[n];
	for(i=0;i<n;i++)
        f[i].taken=P[i].l_hand=P[i].r_hand=0;
 
	while(compltedPhilo<n){
		for(i=0;i<n;i++)
            dining(i,&f[i],&P[i],n);
		printf("\nTill now, %d philosophers has completed dinner.\n\n",compltedPhilo);
	}
 
	return 0;
}
