class Solution {
public:
    vector<vector<string>> ans;
    bool is_palindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void generateAllPartitions(vector<string> cur,string s,int i) 
    {
        if(i==(int)s.size())
        {
            ans.push_back(cur);
            return ;
        }
        // pass by value: new copy of the old variable, copying takes time
        // pass by reference: old copy of the variable is directly used with a different nickname
        for(int j=i;j<(int)s.size();j++)
        {
            if(is_palindrome(s,i,j))
            {
                int len=j-i+1;
                cur.push_back(s.substr(i,len));
                generateAllPartitions(cur,s,j+1);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        generateAllPartitions(cur,s,0);   
        return ans; 
    }
};