class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k),dp(k),cur(k);
        for(int x:nums){
            fill(cur.begin(),cur.end(),0);
            cur[x%k]++;
            for(int r=0;r<k;r++){
                if(dp[r]){
                    cur[(r*(x%k))%k]+=dp[r];
                }
            }
            dp=cur;
            for(int r=0;r<k;r++){
                ans[r]+=dp[r];
            }
        }
        return ans;
    }
};
