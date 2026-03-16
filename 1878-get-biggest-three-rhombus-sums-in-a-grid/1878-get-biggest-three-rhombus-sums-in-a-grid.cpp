class Solution {
public:

    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        set<int> st;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                st.insert(grid[i][j]);
                for(int k=1;k<max(n,m);k++)
                {
                    int x=i,y=j;
                    if(i+2*k>=n || j-k<0 || j+k>=m )break;

                    int sum=0;
                    for(int t=0;t<k;t++) sum+=grid[i+t][j+t];
                    for(int t=0;t<k;t++) sum+=grid[i+k+t][j+k-t];
                    for(int t=0;t<k;t++) sum+=grid[i+2*k-t][j-t];
                    for(int t=0;t<k;t++) sum+=grid[i+k-t][j-k+t];
                    
                    st.insert(sum);
                }
            }
        }

        vector<int> ans;

       for(auto it=st.rbegin();it!=st.rend() && ans.size()<3;it++)
            ans.push_back(*it);

        return ans;
        
    }
};