class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {

        long long ans=0;

        int row=n;
        int col=n;

        vector<bool> rows(n),cols(n);

        for(int i=queries.size()-1;i>=0;i--)
        {
            if(queries[i][0]==1)
            {
                if(!rows[queries[i][1]])
                {
                    rows[queries[i][1]]=true;
                    --row;

                    ans+=queries[i][2]*col;
                }
            }
            else
            {
                if(!cols[queries[i][1]])
                {
                    cols[queries[i][1]]=true;
                    --col;
                    ans+=queries[i][2]*row;
                }
            }
        }
        

        return ans;
    }
};