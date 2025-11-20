class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // Sort: end ascending, start descending
        sort(intervals.begin(), intervals.end(),
            [](auto &a, auto &b){
                if (a[1] == b[1]) return a[0] > b[0];
                return a[1] < b[1];
            }
        );

        int p1 = intervals[0][1] - 1;
        int p2 = intervals[0][1];
        int ans = 2;

        for (int i = 1; i < intervals.size(); i++) {
            int L = intervals[i][0];
            int R = intervals[i][1];

            
            if (L <= p1) continue;

            if (L <= p2) {
                ans++;
                p1 = p2;
                p2 = R;   
            } 
            else {
                ans += 2;
                p1 = R - 1;
                p2 = R;   
            }
        }

        return ans;
    }
};
