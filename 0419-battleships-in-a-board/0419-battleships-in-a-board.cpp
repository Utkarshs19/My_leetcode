class Solution {
public:

    void helper(int i,int j ,int n,int m, vector<vector<char>> &board,vector<vector<bool>> &flag)
    {
        if(i<0 || j<0 || i>=n || j>=m)return;

        if(board[i][j]=='.')return;

        flag[i][j]=true;

        if( i+1<n&&!flag[i+1][j] && board[i+1][j]!='.')
        helper(i+1,j,n,m,board,flag);

        if(j+1<m && !flag[i][j+1] && board[i][j+1]!='.')
        helper(i,j+1,n,m,board,flag);
    }

    int countBattleships(vector<vector<char>>& board) {

        int n=board.size();
        int m=board[0].size();

        vector<vector<bool>> flag(n,vector<bool>(m,false));

        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X' && !flag[i][j])
                {
                    helper(i,j,n,m,board,flag);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};