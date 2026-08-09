class Solution {
public:
    int n;
    int solve(vector<int>&piles,int person,int i,int m,vector<vector<vector<int>>>&dp){
        if(i>=n)return 0;
        if(dp[person][i][m]!=-1)return dp[person][i][m];
        int res=(person==1)? -1:INT_MAX;
        int stone=0;
        for(int x=1;x<=min(2*m,n-i);x++){
            stone+=piles[x+i-1];
            if(person==1){
                res=max(res,stone+solve(piles,0,i+x,max(m,x),dp));
            }
            else{
                res=min(res,solve(piles,1,i+x,max(m,x),dp));
            }
        }
        return dp[person][i][m]=res;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(piles,1,0,1,dp);
    }
};
