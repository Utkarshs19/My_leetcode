class Solution {
public:
    int bestClosingTime(string customers) {
        int ans = 0;
        int mini = 0;
        int prefix = 0;
        
        for (int i = 0; i < customers.length(); i++) {
            prefix += customers[i] == 'Y' ? -1 : 1;
            
            if (prefix < mini) {
                ans = i + 1;
                mini = prefix;
            }
        }
        
        return ans;
    }
};