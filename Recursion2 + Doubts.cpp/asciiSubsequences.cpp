// https://hack.codingblocks.com/app/contests/1496/253/problem
#include<bits/stdc++.h>
using namespace std;

void func(string &s,int i,string &res)
{
	if(i==(int)s.size())
	{
		cout<<res<<" ";
		return ;
	}

	// exclude
	func(s,i+1,res);

	// include char
	res+=(s[i]);
	func(s,i+1,res);
	res.pop_back();


	// include ascii value
	string ascii=to_string((int)s[i]);
	res+=ascii;
	func(s,i+1,res);
	for(int j=0;j<(int)ascii.size();j++) // kitni baar pop_back karana padega?
	{
		res.pop_back();
	}
}

int main()
{
	string s; cin>>s;
	string res="";
	func(s,0,res);
	cout<<endl;
	cout<<(int)(pow(3,(int)s.size())+0.1)<<endl;
	return 0;
}