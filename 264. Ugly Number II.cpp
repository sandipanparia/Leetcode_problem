class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);

        int i2,i3,i5;
        i2=i3=i5=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int i2Min=dp[i2]*2;
            int i3Min=dp[i3]*3;
            int i5Min=dp[i5]*5;
            int mn=min({i2Min,i3Min,i5Min});
            dp[i]=mn;

            if(mn==i2Min){
                i2++;
            }
            if(mn==i3Min){
                i3++;
            }
            if(mn==i5Min){
                i5++;
            }
        }
        return dp[n];
        
    }
};
