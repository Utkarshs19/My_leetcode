class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> cnt(n + 1, 0);
        vector<long long> sum(n + 1, 0);

        vector<int> t;

        for(int i = 0; i < n; i++)
        {
            cnt[i + 1] = cnt[i];
            sum[i + 1] = sum[i] + (s[i] - '0');

            if(s[i] != '0')
            {
                cnt[i + 1]++;
                t.push_back(s[i] - '0');
            }
        }

        int m = t.size();

        vector<long long> pref(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for(int i = 1; i <= m; i++)
        {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
            pref[i] = (pref[i - 1] * 10 + t[i - 1]) % MOD;
        }

        vector<int> ans;

        for(auto &q : queries)
        {
            int l = q[0];
            int r = q[1];

            int L = cnt[l];
            int R = cnt[r + 1];

            int len = R - L;

            long long x = ((pref[R] - pref[L] * pow10[len])) % MOD;
            if(x<0)x+=MOD;

            long long digitSum = sum[r + 1] - sum[l];

            ans.push_back((x * digitSum) % MOD);
        }

        return ans;
    }
};