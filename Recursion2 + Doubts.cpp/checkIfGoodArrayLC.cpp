class Solution {
public:
    int GCD(int a,int b)
    {
        return (b==0?a: gcd(b,a%b));
    }
    bool isGoodArray(vector<int>& A) {
        int g=0;
        for(int i=0;i<(int)A.size();i++)
        {
            g=GCD(g,A[i]);
        }
        return (g==1);
        // if(g==1) return true;
        // return false;
    }
};