class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> m;

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')continue;
                m[board[i][j]]++;
             if(m[board[i][j]]>1)return false;
            }
            
            m.clear();
        }

        for(int i=0;i<board[0].size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[j][i]=='.')continue;
                m[board[j][i]]++;
                 if(m[board[j][i]]>1)return false;
            }
           
            m.clear();
        }


         for(int i=0;i<board.size();i+=3)
        {
            for(int j=0;j<board[0].size();j+=3)
            {   
                for(int a=i;a<i+3;a++)
                {
                    for(int b=j;b<j+3;b++)
                    {
                        if(board[a][b]=='.')continue;
                        m[board[a][b]]++;

                        if(m[board[a][b]]>1)return false;
                    }
                }
               
            m.clear();
            }
            
        }

        return true;

    }
};