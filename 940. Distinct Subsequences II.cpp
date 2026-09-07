class Solution {
public:
    int m=1e9+7;
    vector<int>prev;
    vector<int>dp;
    int solve(int n){
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int t=(2*solve(n-1))%m;

        if(prev[n]!=0){
            int d=solve(prev[n]-1);
            t=(t-d+m)%m;
        }
        return dp[n]=t;
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        dp.assign(n+1,-1);
        prev.assign(n+1,0);
        vector<int>l(26,0);
        for(int i=1;i<=n;i++){
            int ind=s[i-1]-'a';
            prev[i]=l[ind];
            l[ind]=i;
        }
        return (solve(n)-1+m)%m;
    }
};
