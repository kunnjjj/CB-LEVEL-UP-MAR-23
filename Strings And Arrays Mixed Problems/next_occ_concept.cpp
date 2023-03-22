#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin>>s; //26: lower case letters

    int n=s.size();
    vector<vector<int>> next_occ(n+1,vector<int> (26,n));
    for(int i=n-1;i>=0;i--)
    {
        next_occ[i]=next_occ[i+1];
        next_occ[i][s[i]-'a']=i;
    }


    int q; cin>>q;
    while(q--)
    {
        string t; cin>>t;
        int me=-1;
        for(int i=0;i<(int)t.size();i++)
        {
            if(me==n) break;
            me++;
            me=next_occ[me][t[i]-'a'];
        }
        // cout<<"me: "<<me<<endl;
        if(me==n)
        {
            cout<<"not found"<<endl;
        }
        else
        {
            cout<<"found"<<endl;
        }
    }


    return 0;
}