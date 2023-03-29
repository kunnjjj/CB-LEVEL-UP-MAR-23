// https://hack.codingblocks.com/app/contests/1236/502/problem
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin>>n;
	vector<int> A(n+1);
	for(int i=1;i<=n;i++) cin>>A[i];
	stack<int> s;
	for(int i=1;i<=n;i++)
	{
		while(!s.empty() && A[s.top()] <= A[i])
		{
			s.pop();
		}
		int span;
		if(!s.empty())
		{
			span=(i-s.top());
		}
		else span=i;
		cout<<span<<" ";
		s.push(i);
	}
	cout<<"END";
	return 0;
}
