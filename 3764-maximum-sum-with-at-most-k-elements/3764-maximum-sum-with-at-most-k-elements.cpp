class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {

        priority_queue<int> pq;

        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].begin(),grid[i].end());

            int x=limits[i];

            int j=grid[i].size()-1;

            while(x>0)
            {
                pq.push(grid[i][j]);
                j--;
                x--;
            }
        }

        long long int ans=0;
        

        while(!pq.empty()&&k>0)
        {
            ans+=pq.top();
            pq.pop();
            k--;
        }


        return ans;
    }
};