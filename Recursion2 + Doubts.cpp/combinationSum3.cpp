class Solution {
public:
    vector<vector<int>> ans;
    void func(int num,int k,int sum,vector<int> &res)
    {
        // base case
        if(sum==0 and k==0)
        {
            ans.push_back(res);
            return ;
        }

        for(int j=num;j<=min(9,sum);j++)
        {
            res.push_back(j);
            func(j+1,k-1,sum-j,res);
            // backtrack
            res.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        func(1,k,n,res);
        return ans;        
    }
};