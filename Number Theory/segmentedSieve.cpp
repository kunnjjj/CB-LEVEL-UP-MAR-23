#include<iostream>
#include<vector>
using namespace std;
 
long long ceil_div(long long a,int b) // ceiling value of (a/b)
{
    return (a+b-1)/b;
}
 
int max_root_R=1e5;
 
vector<int> sieve(max_root_R+1,1);
 
void make_sieve()
{
    sieve[0]=0;
    sieve[1]=0;
    // for(int i=2;i<=max_root_R;i++)
    for(int i=2;i*i<=max_root_R;i++)
    {
        if(sieve[i]==1) //, mark, 2*i,3*i,4*i,,,, as not prime
        {
            // for(int j=2*i;j<=max_root_R;j+=i)
            for(int j=i*i;j<=max_root_R;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
 
}
// 100000100
 
 
 
 
vector<int> segmented_sieve(long long L,long long R,vector<int> &primes)
{
    vector<int> seg_sieve(R-L+1,1);
    for(int p:primes)
    {
        long long start=max(ceil_div(L,p)*1LL * p,p*1LL*p);
        for(long long j=start;j<=R;j+=p)
        {
            seg_sieve[j-L]=0;
        }
    }
    if(L==1)
    {
        seg_sieve[0]=0;
    }
    return seg_sieve;
}
 
int main()
{
    int t; cin>>t;
    // generate Prime Numbers upto root r
    make_sieve();
 
    vector<int> primes;
    for(int i=0;i<=max_root_R;i++)
    {
        if(sieve[i]==1)
        {
            primes.push_back(i);
        }
    }
    
    // for(int x:primes) cout<<x<<" ";
 
    while(t--)
    {
        long long L,R; cin>>L>>R;
        vector<int> seg_sieve=segmented_sieve(L,R,primes);
        for(int idx=0;idx<(int)seg_sieve.size();idx++)
        {
            if(seg_sieve[idx]==1)
            {
                // j is prime
                // j-L= idx
                cout<<idx+L<<endl;
            }
        }
        cout<<endl;
    }
 
 
    return 0;
} 