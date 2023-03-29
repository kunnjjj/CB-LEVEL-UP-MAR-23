class Solution {
public:
    vector<int> getRightSmaller(vector<int> &H)
    {
        int n=H.size();
        stack<pair<int,int>> s;
        vector<int> right_smaller(n);
        for(int i=0;i<n;i++)
        {
            pair<int,int> cur={H[i],i};
            while(!s.empty() && s.top().first > cur.first)
            {
                right_smaller[s.top().second]=i;
                s.pop();
            }
            s.push(cur);
        }
        while(!s.empty())
        {
            right_smaller[s.top().second]=n;
            s.pop();
        }
        return right_smaller;
    }
    int largestRectangleArea(vector<int>& H) {
        int n=H.size();
        vector<int> right_smaller=getRightSmaller(H);
        reverse(H.begin(),H.end());
        vector<int> left_smaller=getRightSmaller(H); // TODO: CHANGE TO LEFT SMALLER
        reverse(H.begin(),H.end());
        for(int idx=0;idx<n;idx++)
        {
            left_smaller[idx]=(n-1-left_smaller[idx]);
        }
        reverse(left_smaller.begin(),left_smaller.end());

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int Height=H[i],Width=right_smaller[i]-left_smaller[i]-1;
            ans=max(ans,Height*Width);
        }
        return ans;
        // cout<<"right smaller: "<<endl;
        // for(int x:right_smaller) cout<<x<<" ";

        // cout<<endl<<"left_smaller: "<<endl;
        // for(int x:left_smaller) cout<<x<<" ";

    }
};

// .pop()
// .push(val)
// .top()
// .empty() true: when stack is empty and vice-versa
// .size() 




// pair<dataType1,dataType2> p;

// pair<string,int> p;
// pair<string,string> p;
// pair<string,string> p={"aditya","gupta"};

// p.first="aditya";
// p.second="gupta";

// cout<<p.first<<endl;

// p=make_pair("aditya","gupta");




// list l=[1,2,3]
// l.append("abc")



