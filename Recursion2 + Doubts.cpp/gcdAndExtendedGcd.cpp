#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{   
    if(b==0) return a; // gcd(a,0)= a
    
    return gcd(b,a%b);
}

int extended_gcd(int a,int b,int &x1,int &y1)
{
    if(b==0)
    {
        x1=1;
        y1=0;
        return a;
    }

    int x0,y0;
    int g=extended_gcd(b,a%b,x0,y0);
    x1=(y0);
    y1=(x0 - (a/b)*y0);
    return g;
}

int main()
{
    cout<<gcd(10,13)<<endl;

    cout<<gcd(125,80)<<endl;

    int a=30,b=8;
    int x1,y1;
    int g=extended_gcd(a,b,x1,y1);

    cout<<a<<" * "<<x1 <<" + "<<b <<" * "<<y1<<" = "<<g<<endl;

    return 0;
}