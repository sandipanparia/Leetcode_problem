class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int l=0;int r=n-1;
        bool f=1,g=1;
        while(l<n&&v[l]==nums[l])l++;
        while(r>0&&v[r]==nums[r])r--;
        while(l>r)return 0;
        return abs(l-r)+1;
        
    }
};
