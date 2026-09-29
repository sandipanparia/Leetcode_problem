class Solution {
public:
    int n,m;
    #define vll vector<vector<int>> 
    
    bool solve(int i,int j,int cnt,vector<vector<char>>& grid,vector<vll> &dp){
        cnt+=grid[i][j]=='('? 1:-1;
        if(cnt<0)return 0;
        if(dp[i][j][cnt]!=-1)return dp[i][j][cnt];
        if(i==n-1&&j==m-1){
            return cnt==0;
        }

        if(i+1<n){
            if(solve(i+1,j,cnt,grid,dp))return dp[i][j][cnt]=true;
        }

        if(j+1<m){
            if(solve(i,j+1,cnt,grid,dp))return dp[i][j][cnt]=true;
        }
        return dp[i][j][cnt]=false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vll> dp(101,vll(101,vector<int>(201,-1)));
        if((m+n-1)%2)return false;
        if(grid[0][0]==')'||grid[n-1][m-1]=='(')return false;

        return solve(0,0,0,grid,dp);
    }
};
