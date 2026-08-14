class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n + 1);
        for(int x : nums) res[x] = 1;
        vector<int> ans;
        for(int i = 1; i <= n; i++)
            if(res[i] == 0)
                ans.push_back(i);
        return ans;
    }
};
