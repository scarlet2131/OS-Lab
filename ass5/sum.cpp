#include<bits/stdc++.h>
using namespace std;
int n;
int arr[n];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		arr[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}