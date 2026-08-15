class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        bool f=false;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(nums[i]!=0)f=true;
        }
        if(x==0&&f)return n-1;
        else if(!f)return 0;
        else return n;
    }
};
