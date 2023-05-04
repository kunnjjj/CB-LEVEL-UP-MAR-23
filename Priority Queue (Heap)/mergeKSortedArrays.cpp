// https://hack.codingblocks.com/app/contests/1236/1087/problem

#include<bits/stdc++.h>
using namespace std;


#define dataType pair<int,pair<int,int>> 
// { val, {row,col}}

int main()
{   
	int k,n; cin>>k>>n;
	int A[k][n];

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++) cin>>A[i][j];
	}

	priority_queue<dataType,vector<dataType>,greater<dataType>> pq;

	for(int i=0;i<k;i++)
	{
		pq.push({A[i][0],{i,0}}); // {val,{row,col}}
	}
	vector<int> ans;
	while(!pq.empty())
	{
		dataType smallestRightNow=pq.top();
		pq.pop();

		int value=smallestRightNow.first;
		int row=smallestRightNow.second.first;
		int col=smallestRightNow.second.second;

		ans.push_back(value);
		if(col+1 < n) // next element is in range
		{
			dataType toPush={A[row][col+1],{row,col+1}};
			pq.push(toPush);
		}
	}

	for(int i=0;i<n*k;i++) cout<<ans[i]<<" ";


    return 0;
}


// 1	Heap	Find Median from Data Stream	https://leetcode.com/problems/find-median-from-data-stream/
// 2	Heap	K Closest Points to Origin	https://leetcode.com/problems/k-closest-points-to-origin/
// 3	Heap	Merge K sorted arrays	
// 4	Heap	Sort Characters by Frequency	https://leetcode.com/problems/sort-characters-by-frequency/
// 5	Heap	IPO	https://leetcode.com/problems/ipo/