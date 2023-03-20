#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m; cin>>n>>m;

    vector<vector<int>> A(n,vector<int> (m));

    for(int i=0;i<n;i++) 
    for(int j=0;j<m;j++) cin>>A[i][j];

    vector<vector<int>> prefix(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            prefix[i][j]=(j-1>=0?prefix[i][j-1]:0) + A[i][j];
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        prefix[i][j]+=prefix[i-1][j];
    }

    

    return 0;
}