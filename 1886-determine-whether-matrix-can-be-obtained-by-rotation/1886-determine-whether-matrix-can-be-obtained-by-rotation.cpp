class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        int n=mat.size();

        if(mat==target)return true;

        vector<vector<int>> v(n,vector<int>(n));

        for(int time=0;time<n+1;time++)
        {   int k=n-1;
            for(int i=0;i<n;i++)
            {     
                for(int j=0;j<n;j++)
                {
                    v[j][k]=mat[i][j];
                }
                k--;
            }
            mat=v;
            if(v==target)return true;
        }

        return false;
        
    }
};