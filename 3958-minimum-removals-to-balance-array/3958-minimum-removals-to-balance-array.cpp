class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i = 0, ans = 0;
        for (int j = 0; j < n; j++) {
            while (i <= j && nums[j] > (long long)nums[i] * k) {
                i++;
            }
            ans = max(ans, j - i + 1); 
        }

        return n - ans; // min removals
    }
};
