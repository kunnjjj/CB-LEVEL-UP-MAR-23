#include<iostream>
#include<vector>

using namespace std;

int countFactors(int x)
{
    int cnt=0;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            int factor=i;
            int otherFactor=x/i;
            // cout<<factor<<" ";
            cnt++;
            
            if(otherFactor!=i)
            {
                cnt++;
                // cout<<otherFactor<<" ";
            }
        }
    }
    return cnt;
    // cout<<endl;
}


void primeFactorisationRootN(int N)
{
    for(int i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            while(N%i==0)
            {
                cout<<i<<" ";
                N/=i;
            }
        }
    }

    if(N>1)
    {
        // ab jo number bacha hai that is a prime factor and it is N only
        cout<<N<<" ";
    }
}


int max_n=1e6;
vector<int> is_prime(max_n+1,1);
vector<int> max_prime(max_n+1,1);

void make_sieve()
{
    is_prime[0]=0;
    is_prime[1]=0;
    for(int i=2;i*i<=max_n;i++)
    {
        if(is_prime[i]==1)
        {
            for(int j=i*i;j<=max_n;j+=i)
            {
                is_prime[j]=0;
            }
        }
    }
}

void make_max_prime_array()
{
    for(int i=2;i<=max_n;i++)
    {
        if(is_prime[i]==1)
        {
            for(int j=i;j<=max_n;j+=i)
            {
                max_prime[j]=i;
            }
        }
    }
}   

int primeFactors(int x)
{
    int ans=1;
    while(x>1)
    {
        int cur_factor=max_prime[x];
        int cnt=0;
        while(x>1 && max_prime[x]==cur_factor)
        {
            x/=max_prime[x];
            cnt++;
        }
        ans*=(cnt+1);
    }
    return ans;
}


int main()
{
    // primeFactorisationRootN(14);


    make_sieve();
    make_max_prime_array();

    // primeFactors(36);
    int t; cin>>t;
    while(t--)
    {
        int x; cin>>x;
        cout<<primeFactors(x)<<endl;
    }



    return 0;
}