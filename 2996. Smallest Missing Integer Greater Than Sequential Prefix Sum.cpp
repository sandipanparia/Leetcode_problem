class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int s=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]+1==nums[i])s+=nums[i];
            else break;
        }
        while(find(nums.begin(),nums.end(),s)!=nums.end())s++;
        return s;
    }
};
