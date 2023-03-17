#include<bits/stdc++.h>
using namespace std;

// BLACK BOX METHOD
// WE HAVE A MAGICAL FUNCTION FOR NOW THAT GIVES US PI ARRAY

vector<int> prefix_function(string s) { 
    // pi: longest common prefix which is also a suffix
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    
    int m;

    while(cin>>m) //EOF 
    {
        string pattern,text; cin>>pattern>>text;
        string aux=pattern + "#" + text;
        vector<int> pi=prefix_function(aux);

        int idx=0;
        bool found=false;
        for(int i=pattern.size()+1;i<(int)pi.size();i++,idx++)
        {
            if(pi[i]==pattern.size())
            {
                found=true;
                cout<<idx-(int)pattern.size()+1<<endl;
            }
        }
        if(found==false) cout<<endl;
    }



    // for(int i=0;i<(int)pi.size();i++)
    // {
    //     cout<<pi[i]<<" ";
    // }   



    return 0;
}