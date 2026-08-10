// Memoization approach---->
class Solution {
public:
    bool solve(int n,vector<int>&dp){
        if(n==0)return false;
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i*i<=n;i++){
            if(solve(n-i*i,dp)==false)return dp[n]=true;
        }
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
//bottom up approach--->
class Solution {
public:
    bool winnerSquareGame(int n) {
       vector<bool>dp(n+1,false);
        for(int j=0;j<=n;j++){
            for(int i=1;i*i<=j;i++){
                if(dp[j-i*i]==false){dp[j]=true;break;}
            }
        }
        return dp[n];
    }
};
