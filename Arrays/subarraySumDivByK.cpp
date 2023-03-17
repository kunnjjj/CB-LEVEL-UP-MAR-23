class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n=nums.size();
        // vector<int> prefixModK(n);
        int sum=0;
        // for(int i=0;i<n;i++)
        // {
        //     sum=((sum + nums[i])%k + k)%k;
        //     prefixModK[i]=sum;
        // }

        unordered_map<int,int> freq;
        freq[0]=1; // 0 was already found on index=-1

        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum=((sum + nums[i])%k + k)%k;
            // ans+=freq[sum];
            // freq[sum]++;
            ans+=freq[sum]++;
        }
        return ans;

    }
};