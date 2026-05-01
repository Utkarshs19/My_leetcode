class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n=mat.size();int m=mat[0].size();
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                bool flag=true;

                if(i-1>=0 && mat[i-1][j]>mat[i][j])flag=false;
                if(j-1>=0 && mat[i][j-1]>mat[i][j])flag=false;
                if(i+1<n && mat[i+1][j]>mat[i][j])flag=false;
                if(j+1<m && mat[i][j+1]>mat[i][j])flag=false;

                if(flag==true)return {i,j};
            }
        }

        return {};
        
    }
};