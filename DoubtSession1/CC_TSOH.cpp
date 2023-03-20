// https://www.codechef.com/problems/TSOH
#include<bits/stdc++.h>
using namespace std;

int main()
{

    // INT_MAX=[-2^31...2^31-1]
    // INT_MAX[-2*10^9 ....2*10^9]

    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];

    vector<long long> best_left(n);
    // best_left[i]: if i definitely include A[i],
    //  what is the best subarray sum that i can get
    // best_left[i]=max(best_left[i-1] + A[i],A[i])

    for(int i=0;i<n;i++)
    {
        best_left[i]=max((i-1>=0?best_left[i-1]:0) + A[i], // when i continue in old subarray
        (long long)A[i]);
        // new subarray
    }
    long long INF=1e12;
    vector<long long> left_max(n);
    
    for(int i=0;i<n;i++)
    {
        // left_max[i]=max((i-1>=0?left_max[i-1]:-INF),best_left[i]);
        left_max[i]=max((i-1>=0?left_max[i-1]:best_left[0]),best_left[i]);
    }

    vector<long long> best_right(n);
    for(int i=n-1;i>=0;i--)
    {
        best_right[i]=max((i+1<n?best_right[i+1]:0) + A[i],(long long)A[i]);
    }

    vector<long long> right_max(n);
    for(int i=n-1;i>=0;i--)
    {
        right_max[i]=max((i+1<n?right_max[i+1]:-INF),best_right[i]);
    }

    long long ans=-INF;
    for(int i=0;i<=n-2;i++)
    {
        long long k1=left_max[i]; //kadane[0.....i]
        long long k2=right_max[i+1]; // kadane[i+1....n-1]
        ans=max(ans,k1+k2);
    }
    cout<<ans<<endl;





    return 0;
}