class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int i=x,j=x+k-1;

        while(i<=j)
        {
            for(int a=y;a<=y+k-1;a++)
            {
                swap(grid[i][a],grid[j][a]);
            }
            i++;
            j--;
        }

        return grid;

    }
};