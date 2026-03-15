class Solution {
public:
    long long countCommas(long long n) {

        long long sum = 0;

        if(n <= 999) return 0;

        long long cnt;

        cnt = min(999999LL, n) - 1000;
        if(cnt >= 0) sum += (cnt + 1) * 1;

        cnt = min(999999999LL, n) - 1000000;
        if(cnt >= 0) sum += (cnt + 1) * 2;

        cnt = min(999999999999LL, n) - 1000000000;
        if(cnt >= 0) sum += (cnt + 1) * 3;

        cnt = min(999999999999999LL, n) - 1000000000000;
        if(cnt >= 0) sum += (cnt + 1) * 4;

        cnt = min(999999999999999999LL, n) - 1000000000000000;
        if(cnt >= 0) sum += (cnt + 1) * 5;

        return sum;
    }
};