class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int n=board.size();
        int m=board[0].size();
        board[rMove][cMove]=color;
        int cnt=0;

        for(int i=rMove-1;i>=0;i--)
        {
            if(board[i][cMove]!=board[rMove][cMove] && board[i][cMove]!='.')
            cnt++;
            else
            {
                if(board[i][cMove]==color && cnt>=1)return true;
                  break;
            }
        }
        cnt=0;
        for(int i=rMove+1;i<n;i++)
        {
            if(board[i][cMove]!=board[rMove][cMove] && board[i][cMove]!='.')
            cnt++;
            else
            {
                if(board[i][cMove]==color && cnt>=1)return true;
                  break;
            }
        }

        cnt=0;
        for(int i=cMove-1;i>=0;i--)
        {
            if(board[rMove][i]!=board[rMove][cMove] && board[rMove][i]!='.')
            cnt++;
            else
            {
                if(board[rMove][i]==color && cnt>=1)return true;
                  break;
            }
        }
        cnt=0;
        for(int i=cMove+1;i<m;i++)
        {
            if(board[rMove][i]!=board[rMove][cMove] && board[rMove][i]!='.')
            cnt++;
            else
            {
                if(board[rMove][i]==color && cnt>=1)return true;
                break;
            }
        }

        int i=rMove-1,j=cMove-1;
        cnt=0;
        while(i>=0 && j>=0)
        {
            if(board[i][j]!=board[rMove][cMove] && board[i][j]!='.')
            cnt++;
            else
            {
                if(board[i][j]==color && cnt>=1)return true;
                  break;
            }
            i--;
            j--;
        }

        i=rMove+1,j=cMove+1;
        cnt=0;
        while(i<n && j<m)
        {
            if(board[i][j]!=board[rMove][cMove] && board[i][j]!='.')
            cnt++;
            else
            {
                if(board[i][j]==color && cnt>=1)return true;
                  break;
            }
            i++;
            j++;
        }

        i=rMove-1,j=cMove+1;
        cnt=0;
        while(i>=0 && j<m)
        {
            if(board[i][j]!=board[rMove][cMove] && board[i][j]!='.')
            cnt++;
            else
            {
                if(board[i][j]==color && cnt>=1)return true;
                  break;
            }
            i--;
            j++;
        }

        i=rMove+1,j=cMove-1;
        cnt=0;

        while(i<n && j>=0)
        {
            if(board[i][j]!=board[rMove][cMove] && board[i][j]!='.')
            cnt++;
            else
            {
                if(board[i][j]==color && cnt>=1)return true;
                  break;
            }
            i++;
            j--;
        }
        

        return false;

        
    }
};