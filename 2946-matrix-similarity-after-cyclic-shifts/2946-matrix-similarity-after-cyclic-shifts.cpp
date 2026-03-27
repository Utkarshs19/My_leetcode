class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        vector<vector<int>> v=mat;

        k=k%mat[0].size();

        while(k>0)
        {
            for(int i=0;i<mat.size();i++)
            {
                    if(i%2==0)
                    {
                        int x=mat[i][0];
                        for(int j=1;j<mat[0].size();j++)
                        {
                            mat[i][j-1]=mat[i][j];
                        }
                        mat[i][mat[0].size()-1]=x;
                    }
                    else
                    {
                        int x=mat[i][mat[0].size()-1];
                        for(int j=mat[0].size()-2;j>=0;j--)
                        {
                            mat[i][j+1]=mat[i][j];
                        }
                        mat[i][0]=x;
                    }
            }
            k--;
        }
        return mat==v;
    }
};