#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> B(n-1);
    for(int &x:B) cin>>x;
    vector<int> A(n);
    for(int i=0;i<n-1;i++)
    {
        if(i==0 or B[i] < B[i-1])
        {
            A[i]=B[i];
        }
        else
        {
            A[i]=B[i-1];
        }
    }
    A.back()=B.back();
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    cout<<endl;

    for(int i=0;i+1<n;i++)
    {
        assert(B[i]==max(A[i],A[i+1]));
    }

    // assert(condition)
    // agar assert ke andar likhi hui condition fail hoti hai
    // toh error throw hota hai (runtime error)
    // assert()

}
int main()
{
    int t; cin>>t;
    while (t--)
    {
        solve();
        /* code */
    }
    


    return 0;
}