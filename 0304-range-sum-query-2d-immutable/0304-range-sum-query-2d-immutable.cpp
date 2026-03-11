class NumMatrix {
public:
    int n,m;
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
            vector<int> v1(m,0);
            v1[0]=matrix[i][0];
            for(int j=1;j<m;j++)
            {
                v1[j]=v1[j-1]+matrix[i][j];
            }
            v.push_back(v1);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

            int ans=0;

            for(int i=row1;i<=row2;i++)
            {
                if(col1==0)ans+=v[i][col2];
                else
                {
                    ans+=(v[i][col2]-v[i][col1-1]);
                }
            }
            return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */