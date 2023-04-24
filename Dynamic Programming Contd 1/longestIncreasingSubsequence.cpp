#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> &A,vector<int> &dp,int i)
{
    if(dp[i]!=-1) return dp[i];

    dp[i]=1;
    for(int j=i-1;j>=0;j--)
    {
        if(A[j] < A[i])
        dp[i]=max(dp[i],lis(A,dp,j) +1);
    }
    return dp[i];
}

void func(vector<int> :: iterator it)
{
    cout<<"\nprinting A[0]: "<<(*it)<<endl;
}

int get_ans(vector<int> &A)
{
    vector<int> dp;
    // DP IS SORTED
    // len(DP)== len(LIS)
    // ****** RATA HONA CHAHIYE ****** 

    for(int i=0;i<(int)A.size();i++)
    {
        auto it=lower_bound(dp.begin(),dp.end(),A[i]);
        if(it==dp.end())
        {
            dp.push_back(A[i]);
        }
        else
        {
            (*it)=A[i];
        }
    }
    return (int)dp.size();

}

int main()
{
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];

    cout<<get_ans(A)<<endl;

    // vector<int> DP(n,-1);
    // int ans_rec=1;
    // for(int i=0;i<n;i++)
    // {
    //     ans_rec=max(ans_rec,lis(A,DP,i));
    // }
    // cout<<ans_rec<<endl;

















    // vector<int> dp(n,1);

    // // dp[i]=len of LIS upto that at index=i
    // int ans=1;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=i-1;j>=0;j--)
    //     {
    //         if(A[j] < A[i])
    //         {
    //             dp[i]=max(dp[i],1+dp[j]);
    //         }
    //     }
    //     ans=max(ans,dp[i]);
    // }


    // cout<<ans<<endl;

    // for(int x: dp)
    // {
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    // vector<int>:: iterator it;

    // for(it=dp.begin();it!=dp.end();it++)
    // {
    //     cout<<(*it)<<" ";
    // }

    // it=A.begin();
    // func(it);


    return 0;
}