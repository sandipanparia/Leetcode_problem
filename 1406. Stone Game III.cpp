//memoization approach---->
class Solution {
public:
    int solve(int i,vector<int>& stoneValue,vector<int>&dp){
        int n=stoneValue.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int res=INT_MIN;
        res=max(res,stoneValue[i]-solve(i+1,stoneValue,dp));
        if(i+1<n)res=max(res,stoneValue[i]+stoneValue[i+1]-solve(i+2,stoneValue,dp));
        if(i+2<n)res=max(res,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(i+3,stoneValue,dp));
        return dp[i]=res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n,-1);
        int diff=solve(0,stoneValue,dp);
        if(diff>0)return "Alice";
        else if(diff==0)return "Tie";
        else return "Bob";
    }
};

// bottom-up approach---->
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int res=INT_MIN;
            res=max(res,stoneValue[i]-dp[i+1]);
            if(i+1<n)res=max(res,stoneValue[i]+stoneValue[i+1]-dp[i+2]);
            if(i+2<n)res=max(res,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]);
            dp[i]=res;
        }
        int diff=dp[0];
        if(diff>0)return "Alice";
        else if(diff==0)return "Tie";
        else return "Bob";
    }
};
