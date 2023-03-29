class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        int n=H.size();

        int ans=0;
        // stack<pair<int,int>> s;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            // pair<int,int> cur={H[i],i};
            // s.top().first -  {A[idx],idx}
            // s.top() - idx
            while(!s.empty() && H[s.top()] > H[i])
            {
                int right_smaller_for_popped_ele=i;
                int idx=s.top();
                s.pop();
                int left_smaller_for_popped_ele=(s.empty()?-1:s.top());
                int width=right_smaller_for_popped_ele- left_smaller_for_popped_ele-1; 
                ans=max(ans,H[idx] * (width));
            }
            s.push(i);
        }
        while(!s.empty())
        {
            int right_smaller_for_popped_ele=n;
            int idx=s.top();
            s.pop();
            int left_smaller_for_popped_ele=(s.empty()?-1:s.top());
            int width=right_smaller_for_popped_ele- left_smaller_for_popped_ele-1; 
            ans=max(ans,H[idx] * (width));
        }
        return ans;
    }
};