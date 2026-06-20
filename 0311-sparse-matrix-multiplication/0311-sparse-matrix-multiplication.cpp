class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {

        int m=mat1.size();
        int k=mat1[0].size();
        int n=mat2[0].size();

        vector<vector<int>> ans(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<k;j++)
            {
                for(int a=0;a<n;a++)
                {
                    ans[i][a]+=mat1[i][j]*mat2[j][a];
                }
            }
        }
        return ans;
        
    }
};