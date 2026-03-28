class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int n=board.size();
        int m=board[0].size();
        board[rMove][cMove]=color;
        

        int dirs[8][2]={{-1,0},{1,0},{0,-1},{0,1},
                          {-1,-1},{1,1},{-1,1},{1,-1}};

        for(auto d:dirs)
        {
            int i=rMove+d[0];
            int j=cMove+d[1];
            int cnt=0;

            while(i>=0 && j>=0 && i<n && j<m)
            {
                if(board[i][j]!=color && board[i][j]!='.')
                cnt++;
                else
                {
                    if(board[i][j]==color && cnt>=1)return true;
                    break;
                }
                i+=d[0];
                j+=d[1];
            }
        }
        return false;
    }
};