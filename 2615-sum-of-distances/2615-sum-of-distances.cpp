class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for(auto &it : mp) {
            vector<int> &v = it.second;
            int k = v.size();

            vector<long long> prefix(k + 1, 0);
            for(int i = 0; i < k; i++) {
                prefix[i + 1] = prefix[i] + v[i];
            }

            for(int i = 0; i < k; i++) {
                long long left = (long long)i * v[i] - prefix[i];
                long long right = (prefix[k] - prefix[i]) - (long long)(k - i) * v[i];
                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};