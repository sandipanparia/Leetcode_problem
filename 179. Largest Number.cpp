class Solution {
public:
    static bool cmp(int a, int b) {
        string x = to_string(a);
        string y = to_string(b);
        return x + y > y + x;
    }
    string largestNumber(vector<int>& nums) {
       sort(nums.begin(), nums.end(), cmp);

        if (nums[0] == 0) return "0";  

        string s = "";
        for (int num : nums) {
            s += to_string(num);
        }
        return s;
    }
};
