class Solution {
public:
    vector<int>fun(int x){
        vector<int>f;
        for(int p=2;p*p<=x;p++) {
            if(x%p==0){
                f.push_back(p);
                while(x%p==0)x/=p;
            }
        }
        if(x>1)f.push_back(x);
        return f;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>fac(n);
        for(int i=0;i<n;i++){
            fac[i]=fun(nums[i]);
        }
        unordered_map<int,int>cnt;
        int l=0,ans=0;
        int dis=0;
        for(int r=0;r<n;r++){
            for(auto it: fac[r]){
                if(cnt[it]==0)dis++;
                cnt[it]++;
            }
            while(dis>k){
                for(auto it:fac[l]){
                    cnt[it]--;
                    if(cnt[it]==0)dis--;
                }
                l++;
            }
            ans=max(ans,(r-l+1));
        }
        return ans;
    }
};
