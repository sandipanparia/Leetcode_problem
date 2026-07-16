class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int mn=INT_MAX;
        int s=0;
        while(j<n){
            s+=nums[j];
            while(s>=target){
                mn=min(mn,j-i+1);
                s-=nums[i];
                i++;
            }
            j++;
        }
        return mn==INT_MAX? 0:mn;
    }
};
