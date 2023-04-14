#include<bits/stdc++.h>
using namespace std;



int max_n=(int)3e3;
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

    make_sieve();

    // vector<int> primes;
    // for(int i=0;i<(int)sieve.size();i++)
    // {
    //     if(sieve[i]==1) primes.push_back(i);
    // }
    int N; cin>>N;
    int ans=0;
    for(int num=1;num<=N;num++)
    {
        int cnt=0;
        for(int j=1;j<=num;j++)
        {
            if(sieve[j] && num%j==0)
            {
                cnt++;
            }
        }
        
        if(cnt==2)
        {
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}