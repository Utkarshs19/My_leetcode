class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {

        vector<int> v;

        for(int i=0;i<grid.size();)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                v.push_back(grid[i][j]);
            }
            i++;
            for(int j=grid[i].size()-1;j>=0;j--)
            {
                v.push_back(grid[i][j]);
            }
            i++;
        }
        vector<int> ans;

        for(int i=0;i<v.size();i+=2)
        {
            ans.push_back(v[i]);
        }
        return ans;
    }
};