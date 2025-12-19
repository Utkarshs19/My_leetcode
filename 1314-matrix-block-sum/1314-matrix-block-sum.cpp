class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {


        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum=0;
                for(int a=i-k;a<=i+k;a++)
                {
                    for(int b=j-k;b<=j+k;b++)
                    {
                        if(a<0||a>=n)continue;
                        if(b<0||b>=m)continue;

                        sum+=mat[a][b];

                    }
                }
                ans[i][j]=sum;
            }
        }

        return ans;
        
    }
};