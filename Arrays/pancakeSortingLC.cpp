class Solution {
public:
    void flip(vector<int> &A,int s,int e)
    {
        while(s<e)
        {
            swap(A[s],A[e]);
            s++;
            e--;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        for(int op=1;op<=n;op++)
        {
            int idx=-1,large=INT_MIN;
            for(int i=0;i<=n-op;i++)
            {
                if(arr[i] > large)
                {
                    large=arr[i];
                    idx=i;
                }
            }
            flip(arr,0,idx);
            ans.push_back(idx+1);

            flip(arr,0,n-op);
            ans.push_back(n-op+1);
        }
        return ans;
    }
};