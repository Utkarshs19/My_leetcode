class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int cnt=0;

        long long sum =0;

        int mini=INT_MAX;

        for(int i=0;i<matrix.size();i++)
        {
            sort(matrix[i].begin(),matrix[i].end());
            for(int j=0;j<matrix[i].size();j++)
            {
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0)cnt++;

                mini=min(mini,abs(matrix[i][j]));
            }
        }

        if(cnt%2==0)return sum;

        return sum-2LL*mini;

        
    }
};