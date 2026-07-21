class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<int>v;
        int cnt=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)cnt++;
            else{
                cnt=0;
            }
            ans+=cnt;
        }
        return ans;
    }
};
