class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<=100;i++){
            int r=k*i;
            if(!(find(nums.begin(),nums.end(),r)!=nums.end())){
                return r;
            }
        }
        return 101;
    }
};
