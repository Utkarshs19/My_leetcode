class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int n=boxGrid.size();
        int m=boxGrid[0].size();

        vector<vector<char>> ans(m,vector<char>(n));

        for(int i=0;i<n;i++)
        {
            int write = m - 1;

            for (int j = m - 1; j >= 0; j--) {
                ans[j][n-1-i]=boxGrid[i][j];
                if (ans[j][n-1-i] == '*') {
                    write = j - 1;  
                }
                else if (ans[j][n-1-i] == '#') {
                    swap(ans[j][n-1-i], ans[write][n-i-1]);
                    write--;
                }
            }
            
        }


        
        return ans;
        
    }
};