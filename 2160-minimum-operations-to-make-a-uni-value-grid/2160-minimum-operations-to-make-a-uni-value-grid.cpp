class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> v;

        set<int> s;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                s.insert(grid[i][j]%x);
                v.push_back(grid[i][j]);
            }
        }

        if(s.size()>1)return -1;

        sort(v.begin(),v.end());

        int ans=0;

        for(int i=0;i<v.size();i++)
        {
            ans+=(abs(v[v.size()/2]-v[i]))/x;
            
        }

        return ans;
        
    }
};