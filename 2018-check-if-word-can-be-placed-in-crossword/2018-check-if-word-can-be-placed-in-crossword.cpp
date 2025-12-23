class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {

        int n=board.size();
        int m=board[0].size();
        int k=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==' ' || board[i][j]==word[0])
                {
                    k=0;
                    int a=j;
                    while(k<word.length() && a<m)
                    {
                        if(board[i][a]==' ' || board[i][a]==word[k])
                        {
                            a++;
                            k++;
                        }
                        else break;
                    }

                    if(k==word.length())
                    {
                        bool left = (j == 0 || board[i][j - 1] == '#');
                        bool right = (a == m || board[i][a] == '#');
                        if (left && right) return true;
                    }

                }
            }

            for(int j=m-1;j>=0;j--)
            {
                if(board[i][j]==' ' || board[i][j]==word[0])
                {
                    k=0;
                    int a=j;
                    while(k<word.length() && a>=0)
                    {
                        if(board[i][a]==' ' || board[i][a]==word[k])
                        {
                            a--;
                            k++;
                        }
                        else break;
                    }

                    if(k==word.length())
                    {
                        bool right = (j == m - 1 || board[i][j + 1] == '#');
                        bool left = (a == -1 || board[i][a] == '#');
                        if (left && right) return true;
                    }

                }
            }
        }

        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(board[i][j]==' ' || board[i][j]==word[0])
                {
                    k=0;
                    int a=i;
                    while(k<word.length() && a<n)
                    {
                        if(board[a][j]==' ' || board[a][j]==word[k])
                        {
                            a++;
                            k++;
                        }
                        else break;
                    }

                    if(k==word.length())
                    {
                        bool up = (i == 0 || board[i - 1][j] == '#');
                        bool down = (a == n || board[a][j] == '#');
                        if (up && down) return true;
                    }

                }
            }


            for(int i=n-1;i>=0;i--)
            {
                if(board[i][j]==' ' || board[i][j]==word[0])
                {
                    k=0;
                    int a=i;
                    while(k<word.length() && a>=0)
                    {
                        if(board[a][j]==' ' || board[a][j]==word[k])
                        {
                            a--;
                            k++;
                        }
                        else break;
                    }

                    if(k==word.length())
                    {
                        bool down = (i == n - 1 || board[i + 1][j] == '#');
                        bool up = (a == -1 || board[a][j] == '#');
                        if (up && down) return true;
                    }

                }
            }
        }

        return false;
        
    }
};