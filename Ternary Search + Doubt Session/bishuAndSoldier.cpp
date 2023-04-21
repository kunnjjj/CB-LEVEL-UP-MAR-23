#include<bits/stdc++.h>
using namespace std;
// https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/
int main()
{
	int N; cin>>N;
	vector<int> A(N+1);
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
	}
	sort(A.begin()+1,A.begin()+1+N);
	// sort(A.begin()+1,A.end());
 
	vector<int> prefix(N+1);
	prefix[0]=0;
	for(int i=1;i<=N;i++)
	{
		prefix[i]=prefix[i-1] + A[i];
	}
 
	int t; cin>>t;
	while(t--)
	{
		int p; cin>>p;
		int ans_idx=0;
		int s=1,e=N;
		while(s<=e)
		{
			int mid=(s+e)/2;
			if(A[mid] <= p)
			{
				ans_idx=mid;
				s=mid+1;
			}
			else
			{
				e=mid-1;
			}
		}
		cout<<ans_idx<<" ";
		cout<<prefix[ans_idx]<<endl;
	}
 
 
 
 
 
	return 0;
}