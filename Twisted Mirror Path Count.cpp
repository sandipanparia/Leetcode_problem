class Solution {
public:
    int left=0;
    int up=1;
    int mod=1e9+7;
    int n,m;
    int solve(vector<vector<int>>&grid,int i,int j,int f,vector<vector<vector<int>>> &dp){
        if(i>=n||j>=m)return 0;
        if(i==n-1&&j==m-1)return 1;
        if(dp[i][j][f]!=-1)return dp[i][j][f];
        if(grid[i][j]==1){
            if(f==left){
                return solve(grid,i+1,j,up,dp);
            }
            else return solve(grid,i,j+1,left,dp);
        }
        int t=0;
        t=(t+solve(grid,i+1,j,up,dp))%mod;
        t=(t+solve(grid,i,j+1,left,dp))%mod;

        return dp[i][j][f]=t;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return solve(grid,0,0,left,dp);
    }
};
