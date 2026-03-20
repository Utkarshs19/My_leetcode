class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        vector<vector<int>> ans;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<=n-k;i++)
        {
            vector<int> a;
            for(int j=0;j<=m-k;j++)
            {
                vector<int> v;
                for(int a=i;a<i+k;a++)
                {
                    for(int b=j;b<j+k;b++)
                    {
                        v.push_back(grid[a][b]);
                    }
                }
                sort(v.begin(),v.end());

                int diff=INT_MAX;
                for(int x=1;x<v.size();x++)
                {
                    if(v[x]==v[x-1])continue;
                    diff=min(diff,abs(v[x]-v[x-1]));
                }
                if(diff==INT_MAX)diff=0;
                a.push_back(diff);   
            }
            ans.push_back(a);
        }
        return ans;
    }
};