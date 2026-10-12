
class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> isPrime(n + 1, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> ans;
        int sum = 0;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i] && sum + i <= s) {
                sum += i;
                ans.push_back(i);
            }
        }

        return ans;
    }
};
