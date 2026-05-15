class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

        vector<vector<int>> v(n,vector<int>(n,1));
        for(int i=0;i<mines.size();i++)
        {
            v[mines[i][0]][mines[i][1]]=0;
        }

        vector<vector<int>> up(n,vector<int>(n,0));
        vector<vector<int>> down(n,vector<int>(n,0));
        vector<vector<int>> left(n,vector<int>(n,0));
        vector<vector<int>> right(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            up[0][i]=v[0][i];
            down[n-1][i]=v[n-1][i];
            left[i][0]=v[i][0];
            right[i][n-1]=v[i][n-1];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(v[j][i]==1)
                up[j][i]=1+up[j-1][i];
                else
                up[j][i]=0;
            }
            for(int j=1;j<n;j++)
            {
                if(v[i][j]==1)
                left[i][j]=1+left[i][j-1];
                else
                left[i][j]=0;
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=n-2;j>=0;j--)
            {
                if(v[j][i]==1)
                {
                    down[j][i]=1+down[j+1][i];
                }
                else
                down[j][i]=0;
            }
            for(int j=n-2;j>=0;j--)
            {
                if(v[i][j]==1)
                    right[i][j]=1+right[i][j+1];
                else
                right[i][j]=0;
            }
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=min({up[i][j],left[i][j],right[i][j],down[i][j]});
                ans=max(ans,x);
            }
        }
        

        return ans;
    }
};