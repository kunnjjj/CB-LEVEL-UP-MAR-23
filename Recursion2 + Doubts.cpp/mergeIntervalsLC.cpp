class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<(int)intervals.size();i++)
        {
            if(i!=0 && ans.back()[1] >= intervals[i][0]) // last interval of ans is overlapping with current interval then merge them (case1, case2)
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};