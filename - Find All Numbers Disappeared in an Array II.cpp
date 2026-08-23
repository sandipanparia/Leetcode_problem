class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        long long c=lower;
        for(auto x:nums){
            if(x<lower||x>upper)continue;
            if(x>c)ans.push_back({(int)c,x-1});
            c=max((int)c,x+1);
        }
        if(c<=upper)ans.push_back({(int)c,upper});
        return ans;
    }
};
