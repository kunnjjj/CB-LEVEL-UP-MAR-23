#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    int inf=1e9+1;
    vector<int> right(n);
    for(int i=n-1;i>=0;i--)
    {
        right[i]=min((i+1<n?right[i+1]:A[i]),A[i]);
    }
    int cnt=0;
    int left=-1e9;
    for(int i=0;i<n;i++)
    {
        left=max(left,A[i]);
        if(i==n-1 or left<=right[i+1]) cnt++;
    }
    // left[n-2]<=right[n-1]
    cout<<cnt;

    // for(int i=0;i<n-1;i++)
    // {
    //     left=max(left,A[i]);
    //     if(left<=right[i+1]) cnt++;
    // }
    // cout<<cnt<<endl;
    return 0;
}