#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n; cin>>n;
    int k=3;

    // vector<vector<int>> A(n,vector<int> (k));

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<k;j++) cin>>A[i][j];
    // }

    // vector<vector<int>> dp(n,vector<int> (k));


    

    int prevMax=0,prevSecondMax=0,prevMaxKaIdx=-1;



    for(int i=0;i<n;i++)
    {
        int curMax=0,curSecondMax=0,curMaxKaIndex=-1;

        for(int j=0;j<k;j++)
        {
            // j= cur_activity
            int myDp=0;
            int curPoints;
            cin>>curPoints;
            if(j!=prevMaxKaIdx)
            {
                myDp=curPoints + prevMax;
            }
            else
            {
               myDp= curPoints + prevSecondMax;
            }

            if(myDp > curMax)
            {
                curSecondMax=curMax;
                curMax=myDp;
                curMaxKaIndex=j;
            }
            else if(myDp > curSecondMax)
            {
                curSecondMax=myDp;
            }
        }

        // cout<<"curSecondMax: "<<curSecondMax<<endl;
        // cout<<"curMax: "<<curMax<<endl;
        // cout<<"curMaxKaIndex: "<<curMaxKaIndex<<endl;
        // cout<<endl;

        prevSecondMax=curSecondMax;
        prevMax=curMax;
        prevMaxKaIdx=curMaxKaIndex;
    }

    cout<<prevMax<<endl;





    // vector<int> dpOld(k);
    // for(int i=0;i<n;i++)
    // {
    //     vector<int> dpNow(k);
    //     for(int j=0;j<k;j++)
    //     {

    //         // dp[i][j]= what is max points that Taro can
    //         // if days from 0...i have been passed, Taro is on ith day
    //         // he is doing jth activity

    //         // dp[i][j]= A[i][j] + max(dp[i-1][0],...,dp[i-1][j-1],dp[i-1][j+1],.,dp[i-1][k-1]) 
    //         int MAX_ON_PREV_DAY=0;
    //         if(i>0)
    //         for(int x=0;x<k;x++)
    //         {
    //             if(x==j) continue;

    //             // MAX_ON_PREV_DAY=max(MAX_ON_PREV_DAY,dp[i-1][x]);
    //             MAX_ON_PREV_DAY=max(MAX_ON_PREV_DAY,dpOld[x]);
    //         }
    //         // dp[i][j]= A[i][j] + max(dp[i-1][0],...,dp[i-1][j-1],dp[i-1][j+1],.,dp[i-1][k-1]) 
    //         // MAX_ON_PREV_DAY = max(dp[i-1][0],...,dp[i-1][j-1],dp[i-1][j+1],.,dp[i-1][k-1])
            
    //         // dp[i][j]=A[i][j] + MAX_ON_PREV_DAY;
    //         dpNow[j] = A[i][j] + MAX_ON_PREV_DAY;
    //     }
    //     dpOld=dpNow;
    // }

    // // int FINAL_ANS= max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    // int FINAL_ANS= max({dpOld[0],dpOld[1],dpOld[2]});
    // cout<<FINAL_ANS<<endl;

    return 0;
}