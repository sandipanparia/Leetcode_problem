class Solution {
public:
    int n;
    
    int solve(int l,int r,vector<int>&cumSum,vector<vector<int>>&dp){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int score=0;
        for(int mid=l;mid<=r-1;mid++){
            int leftsum=cumSum[mid]-(l>0?cumSum[l-1]:0);
            int rightsum=cumSum[r]-cumSum[mid];

            if(leftsum<rightsum){
                score=max(score,leftsum+solve(l,mid,cumSum,dp));
            }
            else if(rightsum<leftsum){
                score=max(score,rightsum+solve(mid+1,r,cumSum,dp));
            }
            else{
                score=max({score,leftsum+solve(l,mid,cumSum,dp),rightsum+solve(mid+1,r,cumSum,dp)});
            }
        }
        return dp[l][r]=score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>cumSum(n);
        cumSum[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            cumSum[i]=cumSum[i-1]+stoneValue[i];
        }
        return solve(0,n-1,cumSum,dp);
    }
};
