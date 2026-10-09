class Solution {
public:
    int minInsertions(string s) {

        int open = 0, close = 0;
        int j = 0;
        int ans = 0;

        while (j < s.length())
        {
            if (s[j] == '(') open++;
            else
            {
                close++;
                if (j + 1 < s.length() && s[j + 1] != ')') {
                    ans++;
                    close--;
                    if (open > 0) open--;
                    else ans++;         
                }
                else if (j + 1 < s.length() && s[j + 1] == ')')
                {
                    
                    close--;
                    if (open > 0) open--;
                    else ans++;
                    j++;                
                }
            }

            j++;
        }

        while (close > 0)
        {
            if (close >= 2) close = close - 2;
            else {
                ans++;
                close = 0;
            }
            if (open > 0) open--;
            else ans++;
        }

        return ans + 2 * open;
    }
};