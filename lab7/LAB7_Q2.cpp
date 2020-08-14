#include<bits/stdc++.h>
using namespace std;
int n,nf;
int input_arr[100];

int hit=0;
int i,j,k;

int page[100];
int iterartion=0;
 
  int initial_ptr=0;
 int fault_count=0;
int util_bit[50]; 
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
int if_hit(int data)
{
    hit=0;
    for(j=0; j<nf; j++)
    {
        if(page[j]==data)
        {
            hit=1;
            break;
        }
 
    }
 
    return hit;
}
void print()
{
    for (k=0; k<nf; k++)
    {

        if(page[k]!=9999)
            cout<<page[k]<<" ";
    }
    cout<<endl;
 
}
void  total_page_fault()
{
    cout<<"\nTotal no of page faults:"<<" "<<fault_count<<endl;
    cout<<"average_page_fault"<<" "<<(float)fault_count/n;
}

void second_chance(int input_arr[])
{
    
    initial_ptr=0;
    		 fault_count=0;
		    for(i=0; i<nf; i++)
		    {
		        page[i]=9999;
		    }
    for(i=0; i<nf; i++)
    {
        util_bit[i]=0;
    }
    for(i=0; i<n; i++)
    {
        
        if(if_hit(input_arr[i])==0)
        {
        	fault_count++;
            if(util_bit[initial_ptr]==1)
            {
                do
                {
                    util_bit[initial_ptr]=0;
                    initial_ptr++;
                    if(initial_ptr==nf)
                    {
                        initial_ptr=0;
                        iterartion++;
                    }

                }
                while(util_bit[initial_ptr]!=0);
            }
            else(util_bit[initial_ptr]==0);
            {
                page[initial_ptr]=input_arr[i];
                util_bit[initial_ptr]=1;
                initial_ptr++;
            }
            print();
 
        }
        
        else
        {
        	int hitindex=getHitIndex(input_arr[i]);
            if(util_bit[hitindex]==0)
            {
                util_bit[hitindex]=1;
            }
            
    }
    if(initial_ptr==nf)
    {
            initial_ptr=0;
            iterartion++;
    }
            
           
        }
        cout<<iterartion<<endl; 
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
	second_chance(input_arr);

}