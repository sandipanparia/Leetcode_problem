class Solution {
public:
    int minimumK(vector<int>& nums) {
        long long lo = 1, hi = 0;
        for (auto num : nums) hi += num; // safe sum

        auto check = [&](long long k) -> bool {
            long long op = 0;
            for (auto num : nums) {
                op += (num + k - 1) / k; // ceil(num/k)
            }
            // compare safely using double to avoid overflow
            return (double)op <= (double)k * k;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};
