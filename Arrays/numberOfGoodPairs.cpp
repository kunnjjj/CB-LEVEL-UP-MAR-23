class Solution {
public:
    // nC2= n!/((n-2)! * 2!)= n*(n-1)/2
    int nC2(int n)
    {   
        return n*(n-1)/2;
    }
    int numIdenticalPairs(vector<int>& nums) {
        // either hashmap or frequency array of size 101
        vector<int> freq(101,0); 
        for(int i=0;i<(int)nums.size();i++)
        {
            freq[nums[i]]++;
        }
        int ans=0;
        for(int x=1;x<=100;x++)
        {
            ans+=nC2(freq[x]);
        }
        return ans;
    }
};

class Solution {
public:
    // nC2= n!/((n-2)! * 2!)= n*(n-1)/2
    int nC2(int n)
    {   
        return n*(n-1)/2;
    }
    int numIdenticalPairs(vector<int>& nums) {
        // either hashmap or frequency array of size 101
        vector<int> freq(101,0); 
        int ans=0;
        for(int i=0;i<(int)nums.size();i++)
        {
            ans+=freq[nums[i]];
            // the old elements which contributed to freq[nums[i]]
            // all these can make a pair with current element 'i'
            freq[nums[i]]++;
        }
        return ans;
    }
};

class Solution {
public:
    // nC2= n!/((n-2)! * 2!)= n*(n-1)/2
    int nC2(int n)
    {   
        return n*(n-1)/2;
    }
    int numIdenticalPairs(vector<int>& nums) {
        // either hashmap or frequency array of size 101
        // vector<int> freq(101,0); 
        unordered_map<int,int> freq;
        int ans=0;
        for(int i=0;i<(int)nums.size();i++)
        {
            ans+=freq[nums[i]];
            // the old elements which contributed to freq[nums[i]]
            // all these can make a pair with current element 'i'
            freq[nums[i]]++;
        }
        return ans;
    }
};
