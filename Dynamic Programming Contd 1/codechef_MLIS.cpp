#include<bits/stdc++.h>
using namespace std;

vector<int> get_ans(vector<int> &A)
{
    int n=A.size();
    vector<int> ans(n);
    vector<int> dp;

    for(int i=0;i<n;i++)
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
        ans[i]=(int)dp.size();
    }
    return ans;
}

void test_case()
{
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];

    vector<int> left=get_ans(A);

    // left[i]= MAX LEN OF LIS IN RANGE (0....i)

    reverse(A.begin(),A.end());
    for(int i=0;i<n;i++) A[i]*=-1;

    // LIS(A)= LDS(Rev(A)) = LIS( - REV(A))
    vector<int> right=get_ans(A);

    reverse(right.begin(),right.end());

    // right[i]= MAX LEN OF LIS IN RANGE(i...N-1)

    int ans=left[n-1]; // right[0]

    for(int i=0;i+1<n;i++)
    {
        ans=max(left[i]+right[i+1],ans);
    }
    cout<<ans<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        test_case();
    }

    return 0;
}