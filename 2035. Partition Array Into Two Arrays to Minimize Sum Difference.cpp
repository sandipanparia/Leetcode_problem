class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for (int x : nums) {
            total_sum += x;
        }

        // Step 1: Split the array into two halves
        int half_n = n / 2;
        vector<int> left_half(nums.begin(), nums.begin() + half_n);
        vector<int> right_half(nums.begin() + half_n, nums.end());

        // Step 2 & 3: Generate all sums for each half, grouped by count
        // left_sums[k] = list of sums using k elements from the left half
        vector<vector<int>> left_sums(half_n + 1);
        vector<vector<int>> right_sums(half_n + 1);

        // Helper function to generate sums
        auto generate_sums = [&](const vector<int>& arr, vector<vector<int>>& sums) {
            int len = arr.size();
            for (int i = 0; i < (1 << len); ++i) {
                int current_sum = 0;
                int count = 0;
                for (int j = 0; j < len; ++j) {
                    if ((i >> j) & 1) { // If the j-th bit is set
                        current_sum += arr[j];
                        count++;
                    }
                }
                sums[count].push_back(current_sum);
            }
        };

        generate_sums(left_half, left_sums);
        generate_sums(right_half, right_sums);
        
        // Sort the right_sums lists to prepare for binary search
        for (int i = 0; i <= half_n; ++i) {
            sort(right_sums[i].begin(), right_sums[i].end());
        }

        int min_diff = INT_MAX;

        // Step 4: Combine sums and find the minimum difference
        for (int k = 0; k <= half_n; ++k) {
            // We need k elements from the left and (half_n - k) from the right
            int right_k = half_n - k;
            
            for (int s1 : left_sums[k]) {
                // For this s1, the ideal total sum is total_sum / 2
                // So the ideal s2 from the right half would be:
                int target_s2 = (total_sum / 2) - s1;

                // Use binary search (lower_bound) to find s2 in right_sums[right_k]
                auto& candidates = right_sums[right_k];
                auto it = lower_bound(candidates.begin(), candidates.end(), target_s2);

                // Check the element at the found position
                if (it != candidates.end()) {
                    int s2 = *it;
                    int partition1_sum = s1 + s2;
                    int partition2_sum = total_sum - partition1_sum;
                    min_diff = min(min_diff, abs(partition1_sum - partition2_sum));
                }
                
                // Also check the element just before it, as it might be closer
                if (it != candidates.begin()) {
                    int s2 = *(--it);
                    int partition1_sum = s1 + s2;
                    int partition2_sum = total_sum - partition1_sum;
                    min_diff = min(min_diff, abs(partition1_sum - partition2_sum));
                }
            }
        }

        return min_diff;
    }
};
