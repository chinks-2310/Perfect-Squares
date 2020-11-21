class Solution {
public:
    int numSquares(int n) {
        if(n<=3)
        {
            return n;
        }
        if(checkPerfectSquare(n))
        {
            return 1;
        }
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<dp.size();i++)
        {
            dp[i]=i;
            for(int j=1;j*j<=i;j++)
            {
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
    bool checkPerfectSquare(int n)
    {
        int num=sqrt(n);
        if(num*num==n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
