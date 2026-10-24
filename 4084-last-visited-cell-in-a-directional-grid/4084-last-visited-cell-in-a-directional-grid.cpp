class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        vis[0][0]=1;
        
        int i=0,j=0;

        while(true)
        {
        int new_i=i,new_j=j;
        if(grid[i][j]=='R')new_j=new_j+1;
        else if(grid[i][j]=='L')new_j=new_j-1;
        else if(grid[i][j]=='U')new_i=new_i-1;
        else if(grid[i][j]=='D')new_i=new_i+1;

        if(new_i<0 || new_i>=n ||new_j<0 || new_j>=m || vis[new_i][new_j])return {i,j};

        vis[new_i][new_j]=1;
        i=new_i;
        j=new_j;
        }

        return {};
    }
};