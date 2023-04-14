#include<iostream>
#include<vector>
using namespace std;

bool is_prime(int x) 
{
    if(x<=1) return false;

    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

int max_n=(int)1e6;
vector<int> sieve(max_n+1,1);

void make_sieve()
{
    sieve[0]=0;
    sieve[1]=0;
    // for(int i=2;i<=max_n;i++)
    for(int i=2;i*i<=max_n;i++)
    {
        if(sieve[i]==1) //, mark, 2*i,3*i,4*i,,,, as not prime
        {
            // for(int j=2*i;j<=max_n;j+=i)
            for(int j=i*i;j<=max_n;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int a,b; cin>>a>>b;
        int ans=0;
        for(int i=a;i<=b;i++)
        {
            ans+=sieve[i];
        }
        cout<<ans<<endl;
    }
    // O(T * B^3/2)=10^12 


    return 0;
}