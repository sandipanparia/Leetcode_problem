class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            x=max(x,nums[i]);
            int mn=INT_MAX;
            for(int j=i;j<n;j++){
                mn=min(mn,nums[j]);
            }
            if(x-mn<=k)return i;
        }
        return -1;
    }
};
