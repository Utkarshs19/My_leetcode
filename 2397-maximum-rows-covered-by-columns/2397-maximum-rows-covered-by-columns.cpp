class Solution {
public:
    int r,c;
    int ans=0;
    void helper(int i,vector<vector<int>> &matrix,vector<int> &rows,int numSelect)
    {
        if(numSelect<0)return;
        if(numSelect==0)
        {
            int cnt=0;
            for(int i=0;i<rows.size();i++)
            {
                if(rows[i]==0)cnt++;
            }
            ans=max(ans,cnt);
            return;
        }
        if(i>=c)return;

        for(int j=0;j<r;j++)
        {
            if(matrix[j][i]==1)
            {
                matrix[j][i]=-1;
                rows[j]--;
            }
        }
        helper(i+1,matrix,rows,numSelect-1);
        for(int j=0;j<r;j++)
        {
            if(matrix[j][i]==-1)
            {
                matrix[j][i]=1;
                rows[j]++;
            }
        }
        helper(i+1,matrix,rows,numSelect);
    }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        r=matrix.size();
        c=matrix[0].size();
        vector<int> rows;
        for(int i=0;i<r;i++)
        {
            int cnt=0;
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==1)cnt++;
            }
            rows.push_back(cnt);
        }

        helper(0,matrix,rows,numSelect);

        return ans;
    }
};