class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

       int i=0;
       int cnt=0;
       long long ListMax=0;
       while(ListMax < n)
       {
           if(i<(int)nums.size() && nums[i]<=ListMax+1)
           {
               ListMax=ListMax+nums[i];
                //    [1.....ListMax]
                //    [1.....ListMax+nums[i]]
                i++;
           }
           else
           {
               // new element needs to be patched
               ListMax+=(ListMax+1);
               cnt++;
           }
       }

        // if listmax=15
        // this implies that all element from [1...15] can be made using some combination of array+patched elements

       return cnt;
    }
};