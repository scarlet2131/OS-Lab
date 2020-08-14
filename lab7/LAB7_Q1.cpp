#include<bits/stdc++.h>
using namespace std;

int n,nf;
int input_arr[100];

int hit_c=0;
int i,j,k;

int page[100];
 

 int fault_count=0;

void initialize()
{
    fault_count=0;
    for(i=0; i<nf; i++)
        page[i]=9999;
}
 
int hit(int data)
{
    hit_c=0;
    for(j=0; j<nf; j++)
    {
        if(page[j]==data)
        {
            hit_c=1;
            break;
        }
 
    }
 
    return hit_c;
}
 
int getHitIndex(int data)
{
    int hitind;
    for(k=0; k<nf; k++)
    {
        if(page[k]==data)
        {
            hitind=k;
            break;
        }
    }
    return hitind;
}
 
void print()
{
    for (k=0; k<nf; k++)
    {

        if(page[k]!=9999)
            cout<<page[k]<<" ";
    }
 
}
 
void total_page_fault()
{
    cout<<"\nTotal no of page faults:"<<" "<<fault_count<<endl;
    cout<<"average_page_fault"<<" "<<(float)fault_count/n;
}
void LRU()
{
    initialize();
 
    int least[50];
    for(i=0; i<n; i++)
    {
 
      // cout<<input_arr[i];
 
        if(hit(input_arr[i])==0)
        {
 
            for(j=0; j<nf; j++)
            {
                int pg=page[j];
                int found=0;
                for(k=i-1; k>=0; k--)
                {
                    if(pg==input_arr[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0; j<nf; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            page[repindex]=input_arr[i];
            fault_count++;
 
            print();
            cout<<endl;
        }
        else
        {
          // cout<<"no_page_fault"<<endl;
        }
    }
    total_page_fault();
}
 
void FIFO()
{
    initialize();
    for(i=0; i<n; i++)
    {
       //cout<<input_arr[i];
 
        if(hit(input_arr[i])==0)
        {
 
            for(k=0; k<nf-1; k++)
                page[k]=page[k+1];
 
            page[k]=input_arr[i];
            fault_count++;
            print();
            cout<<endl;
        }
        else
        {
           // cout<<"no_page_fault"<<endl;
        }
    }
    total_page_fault();
}
 
 
void OPTIMAL()
{
    initialize();
    int near[50];
    for(i=0; i<n; i++)
    {
 
        //cout<<input_arr[i];
 
        if(hit(input_arr[i])==0)
        {
 
            for(j=0; j<nf; j++)
            {
                int pg=page[j];
                int found=0;
                for(k=i; k<n; k++)
                {
                    if(pg==input_arr[k])
                    {
                        near[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    near[j]=9999;
            }
            int max=-9999;
            int repindex;
            for(j=0; j<nf; j++)
            {
                if(near[j]>max)
                {
                    max=near[j];
                    repindex=j;
                }
            }
            page[repindex]=input_arr[i];
            fault_count++;
 
            print();
            cout<<endl;
        }
        else
        {
           // cout<<"no_page_fault"<<endl;
        }
    }
    total_page_fault();
}
 

 

 

 
int main()
{
    int choice_;
    cout<<"\nReference_Sequence_number:";
    cin>>n;
    cout<<"\nEnter the page reference sequence:";
    for(i=0; i<n; i++)
        cin>>input_arr[i];
    cout<<"\nEnter no of frames:";
    cin>>nf;
    while(1)
    {
        cout<<"\nPage Replacement Algorithms\n1.FIFO\n2.Optimal\n3.LRU\nExit\nEnter your choice:";
      /* cin>>choice_;
        if(choice_==1)
        {
            getData();
        }*/
        int k;
        cin>>k;
        if(k==1)
        {
            FIFO();
            break;
        }
            else if(k==2)
            {
                OPTIMAL();
                break;
            }
        else if(k==3)
        {
            LRU();
            break;
        }
            else
            {
                return 0;
                break;
            }
        
    }
}
