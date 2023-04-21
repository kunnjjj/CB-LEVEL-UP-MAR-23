//{ Driver Code Starts
/* Driver program to test above function */
// https://practice.geeksforgeeks.org/problems/optimum-location-of-point-to-minimize-total-distance/1/
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class point
{
    public:
    double x;
    double y;
    point(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
};




class Solution{
    public:
    
    double distance(point A,point B)
    {
        return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
    }
    
    double get_func(double X,double a,double b,double c,vector<pair<int,int>> &p)
    {
        // RETURNS SUM OF DISTANCES OF THE POINT WITH GIVEN X CO_ORDINATE WITH REST OF THE CO_CORDINATES
        double Y=(-c - a*X)/b;
        
        point me(X,Y); // me lies on given line aX + bY+c=0
        double ans=0;
        
        for(int i=0;i<(int)p.size();i++)
        {
            point him(p[i].first,p[i].second);
            ans+=distance(me,him);
        }
        return ans;
    }
    
                        // tuple <a,b,c>          // vector or co ordinates
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    //Write your code here
	    
	    double a=get<0> (l);
	    double b=get<1> (l);
	    double c=get<2> (l);
	    
	   // PROPOSE A POINT X, THAT LIES ON THE LINE
	   // aX + bY= C
	   
	   //F(X)= sum of distances of (X,Y) from REST OF ALL THE POINTS 
	   int inf=(int)1e7;
	   double x_start=-inf, x_end=+inf;
	   //F(X_start)= + inf
	   //F(x_end)= +inf
	   
	   double eps=1e-6;
	   
	   while( x_end- x_start > eps) // TODO
	   {
	       double m1=x_start + (x_end-x_start)/3;
	       double m2=x_end - (x_end-x_start)/3;
	       
	       double F_m1 = get_func(m1,a,b,c,p);
	       double F_m2= get_func(m2,a,b,c,p);
	       
	       //[s.....m1......m2....e]
	       
	       if(F_m1 > F_m2)
	       {
	           x_start=m1;
	       }
	       else if(F_m1 < F_m2)
	       {
	           x_end=m2;
	       }
	       else
	       {
	           //[m1.....m2]
	           x_start=m1;
	           x_end=m2;
	       }
	   }
	   // x_start is roughly equal to x_end
	   // x_start + eps= x_end and eps is very small
	   return get_func(x_start,a,b,c,p);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

// } Driver Code Ends