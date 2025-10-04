class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // multiset to maintain the elements within the current window
        multiset<int> m;
        int i = 0,j=0, ans = 0;

            while(j<nums.size()) {
            m.insert(nums[j]);

            // Check if the absolute difference between the maximum and minimum
            // values in the current window exceeds the limit
            while (*m.rbegin() - *m.begin() > limit) {
                // Remove the element at the left pointer from the multiset
                m.erase(m.find(nums[i]));
                // Move the left pointer to the right to exclude the element
                // causing the violation
                ++i;
            }

            // Update maxLength with the length of the current valid window
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};