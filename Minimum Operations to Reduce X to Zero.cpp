class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int s=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            s+=nums[i];
            mp[s]=i;
        }
        if(s<x)return -1;
        int r=s-x;
        s=0;
        int l=INT_MIN;
        
        for(int i=0;i<n;i++){
            s+=nums[i];
            int f=s-r;
            if(mp.find(f)!=mp.end()){
                l=max(l,i-mp[f]);
            }
        }
        return l==INT_MIN ? -1: n-l;
    }
};
