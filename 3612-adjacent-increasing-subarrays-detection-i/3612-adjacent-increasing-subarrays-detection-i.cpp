class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return true;
        if (n < 2 * k) return false; // need at least two subarrays of size k

        // Helper lambda to check if subarray [l, r] is strictly increasing
        auto isIncreasing = [&](int l, int r) {
            for (int i = l + 1; i <= r; i++) {
                if (nums[i] <= nums[i - 1])
                    return false;
            }
            return true;
        };

        // Check for consecutive increasing subarrays
        for (int i = 0; i + 2 * k <= n; i++) {
            bool first = isIncreasing(i, i + k - 1);
            bool second = isIncreasing(i + k, i + 2 * k - 1);
            if (first && second) return true;
        }

        return false;
    }
};
