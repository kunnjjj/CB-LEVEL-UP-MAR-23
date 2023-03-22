class Solution {
public:
    int ans;
    bool is_perf_square(int x)
    {
        int root=sqrt(x)+0.1 ; // TODO EXPLANATION
        return (root*root==x);
    }
    void generate(int i,vector<int> &nums)
    {
        // cout<<"i in func: "<<i<<endl;
        if(i==(int)nums.size())
        {
            // for(int x:nums) cout<<x<<" ";
            // cout<<endl;
            ans++;
            return ;
        }
        set<int> considered;
        for(int j=i;j<(int)nums.size();j++)
        {

            if(considered.find(nums[j])==considered.end()) // if nums[j] has not been considered till now
            { 
                if(i==0 or is_perf_square(nums[i-1] + nums[j]))
                {
                    // cout<<"i: "<<i<<endl;
                    // cout<<"nums[i]: "<<nums[i]<<endl;
                    swap(nums[i],nums[j]);
                    // cout<<"i+1: "<<i+1<<endl;
                    generate(i+1,nums);
                    swap(nums[i],nums[j]);
                    considered.insert(nums[j]);
                }
            }
        }
    }

    int numSquarefulPerms(vector<int>& nums) {
        // directy unique and squarefull permutations generate ho jaye
        ans=0;
        generate(0,nums);
        return ans;
    }
};
        // saari unique permutations generate karo,
        // if permutation if squareful then ans++

        // for(int i=0;i+1<n;i++)
        // {
        //     if(!is_perf(A[i] + A[i+1])) return false;
        // }
        // return true;
        // A=[2,2,4]
        // 3! permuations genarate honge
        // [2a,2b,4]
        // [2b,2a,4]
        // [2a,4,2b]
        // [2b,4,2a]
        // [4,2a,2b]
        // [4,2b,2a]