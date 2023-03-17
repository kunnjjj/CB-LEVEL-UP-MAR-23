#include<bits/stdc++.h>
using namespace std;
int p=37, // smaller (prime) number
M= (int)1e9+7;  // large (prime) number
// 1ex-> 10^x: 1e9->10^9

int mod_add(int a,int b)
{
    return (a%M + b%M)%M;
}

int mod_mul(int a,int b)
{
    return (((long long)a)%M * b%M)%M;
}

int mod_diff(int a,int b){
    return ((a%M - b%M)%M + M) %M;
}

vector<int> getTextArray(string &text)
{
    int n=text.size();
    vector<int> textArray(n);
    int power=1;
    for(int i=0;i<n;i++)
    {
        // textArray[i]=(textArray[i-1] + power* text[i])%M;
        textArray[i]= mod_add((i-1>=0?textArray[i-1]:0),mod_mul(power,(int)text[i]));
        // power*=p;
        power=mod_mul(power,p);
    }  

    return textArray;
}

int getPatternCode(string &pattern)
{
    int code=0;
    int power=1;
    for(int i=0;i<(int)pattern.size();i++)
    {
        code=mod_add(code,mod_mul(power,pattern[i]));
        // power*=p;
        power=mod_mul(power,p);
    }

    return code;
}

vector<int> getPowerArray(int n)
{
    vector<int> powerArray(n);
    int power=1;
    for(int i=0;i<n;i++)
    {
        powerArray[i]=power;
        power=mod_mul(power,p);
    }
    return powerArray;
}

int main()
{
    // string text="abckunjabcdkunjpqrkunjabhishek";
    // string pattern="kunj";
    string text,pattern; cin>>text>>pattern;

    vector<int> textArray=getTextArray(text);
    int patternCode=getPatternCode(pattern);
    // vector<int> patternArray=getTextArray(pattern);
    // patternCode=patternArray.back();

    cout<<"textArray: "<<endl;
    for(int i=0;i<(int)textArray.size();i++) cout<<textArray[i]<<" ";
    cout<<endl;

    cout<<"patternCode: "<<patternCode<<endl;

    vector<int> powerArray=getPowerArray((int)textArray.size());

    int m=pattern.size();
    for(int L=0;L+m-1<(int)text.size();L++)
    {
        int R=L+m-1;
        // text.substr(L,(R-L+!))==pattern // O(len)
        if(mod_diff(textArray[R],(L-1>=0?textArray[L-1]:0))==mod_mul(powerArray[L],patternCode))
        {
            cout<<L<<endl;
        }
    }
    // O(n + m + n)= O(m+n)

    return 0;
}