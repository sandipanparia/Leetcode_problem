class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int m=n/2;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==m)continue;
            ans+=abs(nums[m]-nums[i]);
        }
        return ans;
    }
};
