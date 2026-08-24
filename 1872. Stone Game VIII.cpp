//Recursion and memoization code---->
class Solution {
public:
    int n;
    int solve(int i,vector<int>& stones,vector<int>&pr, vector<int>&dp){
        if(i==n-1)return pr[i];
        if(dp[i]!=-1)return dp[i];
        int take=pr[i]-solve(i+1,stones,pr,dp);
        int skip=solve(i+1,stones,pr,dp);
        return dp[i]=max(take,skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        vector<int>pr(n,0);
        vector<int>dp(n+1,-1);
        pr[0]=stones[0];
        for(int i=1;i<n;i++){
            pr[i]=pr[i-1]+stones[i];
        }
        return solve(1,stones,pr,dp);
    }
};


//Bottom Up Approach----->

class Solution {
public:
    int n;
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        vector<int>pr(n,0);
        vector<int>dp(n+1,0);
        pr[0]=stones[0];
        for(int i=1;i<n;i++){
            pr[i]=pr[i-1]+stones[i];
        }
        dp[n-1]=pr[n-1];
        for(int i=n-2;i>=1;i--){
            int take=pr[i]-dp[i+1];
            int skip=dp[i+1];
            dp[i]=max(take,skip);
        }
        return dp[1];
    }
};
