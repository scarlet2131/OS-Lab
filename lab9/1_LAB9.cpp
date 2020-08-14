#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c;
	cin>>c;
	int n;
	cin>>n;
	int x,y,z;
	//vector<pair<ll,pair<ll,ll> > > v2;
	vector<pair<int,pair<int,int> > >v;
	pair<int,int> p;
	cout<<"Enter the cylinder no and request arrival time"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>z;
		p=make_pair(y,z);
		v.push_back(make_pair(x,p));
	}
	int speed;
	cin>>speed;
	/*for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;

	}*/
	if(c==1)
	{
				vector<pair<int,pair<int,int> > >v1;
				pair<int,int> p2;
				for(int i=0;i<n;i++)
				{
					p2=make_pair(v[i].first,v[i].second.second);
					v1.push_back(make_pair(v[i].second.first,p2));
				}
				sort(v1.begin(),v1.end());
				for(int i=0;i<n;i++)
				{
					cout<<v1[i].first<<" "<<v1[i].second.first<<" "<<v1[i].second.second<<endl;
				}
				//waiting time vector
				vector<pair<double,pair<int,int> > >v2;
				pair<int,int> p1;
				double wait=0;
				double d;
				for(int i=0;i<n;i++)
				{
					//cout<<"wait"<<" "<<wait<<endl;
					d+=(double)v1[i].second.second/(double)speed;
					//cout<<"d"<<" "<<d<<endl;
					p1=make_pair(v1[i].first,v1[i].second.first);
					v2.push_back(make_pair((double)wait,p1));
					wait=(d-(double)v1[i+1].first);


				}
				for(int i=0;i<n;i++)
				{
					cout<<v2[i].first<<" "<<v2[i].second.first<<" "<<v2[i].second.second<<endl;
				}
				cout<<"average waiting time"<<endl;
				double sum=0;
				for(int i=0;i<n;i++)
				{
					sum+=v2[i].first;
				}
				cout<<sum/n<<endl;
				cout<<"Turn Around time"<<endl;

				for(int i=0;i<n;i++)
				{
					cout<<v2[i].first+v1[i].second.second/(double)speed<<endl;
				}
				cout<<endl;
		}
		else if(c==2)
		{
				
		}



}
