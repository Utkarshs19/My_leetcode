class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if (n == 0) return "0";
        
        string ans = "";
        if ((n < 0) ^ (d < 0)) ans = "-";
        
        // Use long long to avoid overflow
        long long x = llabs((long long)n);
        long long y = llabs((long long)d);
        
        long long quo = x / y;
        long long rem = x % y;
        ans += to_string(quo);
        
        if (rem == 0) return ans;
        
        ans += ".";
        unordered_map<long long, int> m;
        
        while (rem) {
            if (m.find(rem) != m.end()) {
                int pos = m[rem];
                ans.insert(pos, "(");
                ans += ")";
                break;
            }
            m[rem] = ans.size();
            rem *= 10;
            quo = rem / y;
            rem %= y;
            ans += to_string(quo);
        }
        
        return ans;
    }
};
