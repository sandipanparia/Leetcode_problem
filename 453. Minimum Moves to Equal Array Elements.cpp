class Solution {
public:
    int minMoves(vector<int>& nums) {
        int s=accumulate(nums.begin(),nums.end(),0);
        int mn=*min_element(nums.begin(),nums.end());
        return s-nums.size()*mn;
    }
};
