#include<bits/stdc++.h>
using namespace std;

void solve(int n,int c)
{
    vector<int> A(n+1); // O(N)
    for(int i=1;i<=n;i++) cin>>A[i];

    vector<long long> prefix(n+1); //O(N)
    for(int i=1;i<=n;i++) prefix[i]=prefix[i-1] + A[i];

    vector<int> last_bar(c,-1); //O(C)
    // last_bar[x] (prefix[i]%c==x) was found at what index

    last_bar[0]=0;
    for(int i=1;i<=n;i++) // O(N)
    {
        int MOD=prefix[i]%c;
        if(last_bar[MOD]!=-1)
        {   
            for(int j=last_bar[MOD]+1;j<=i;j++) // O(N)
            {
                cout<<j<<" ";
            }
            cout<<endl;
            return ;
        }
        last_bar[MOD]=i;
    }
    // O(N+C)
}
int main()
{

    while(1)
    {
        int c,n;
        cin>>c>>n;
        if(c==0 && n==0)
        {
            break;
        }

        solve(n,c);
    }


    return 0;
}