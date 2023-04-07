// DP WHICH GIVES TLE
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int> (n));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]=='(' && s[j]==')')
                {
                    if(i+1==j) // base case
                    {
                        dp[i][j]=true;
                    }
                    else if(i+1<=j-1 && dp[i+1][j-1]==true) // CORNER CASE
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        for(int k=i+1;k<=j-2;k++) // CORNER CASE
                        {
                            if(dp[i][k]==true && dp[k+1][j]==true)
                            {
                                dp[i][j]=true;
                                break;
                            }
                        }   
                    }
                    if(dp[i][j])
                    {
                        ans=max(ans,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};

// STACK
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size();
        int ans=0;
        stack<int> STACK;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') STACK.push(i); // wait karo, you will find someone
            else // closing bracket mila
            {
                if(!STACK.empty() && s[STACK.top()]=='(') // top wale element ka pyaar milgya
                {
                    STACK.pop();
                    int start_idx=(!STACK.empty()?STACK.top()+1:0),end_idx=i;
                    ans=max(ans,end_idx-start_idx+1);
                }
                else // PUSH index of closing brack
                {
                    // THIS INDEX WILL GET GET POPPED
                    STACK.push(i);
                }
            }
        }
        return ans;
    }
};

// DP WITHOUT TLE (different state)
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size();
        int ans=0;
        vector<int> dp(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') dp[i]=0;
            else 
            {
                if(i>=1 && s[i-1]=='(')
                {
                    dp[i]=2+(i-2>=0?dp[i-2]:0);
                }
                else if(i-1>=1)
                {
                    if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
                    {
                        dp[i]=2 + dp[i-1] + (i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0); 
                    }
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};

// HW: do using hashmap
