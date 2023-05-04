// https://leetcode.com/problems/k-closest-points-to-origin/description/
class Solution {
public:
    int getDist(vector<int> &point)// {x0,y0}
    {
        int x=point[0],y=point[1];
        return (x*x  + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<dataType> pq;
        priority_queue<pair<int,int>> pq;
        // {SquareOfDist,index}
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            int distOfPoint=getDist(points[i]);
            if((int)pq.size() + 1 <=k)
            {
                pq.push({distOfPoint,i});
            }
            else if(distOfPoint < pq.top().first)
            {
                pq.pop();
                pq.push({distOfPoint,i});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty())
        {
            int idx=pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();
        }
        return ans;
    }
};