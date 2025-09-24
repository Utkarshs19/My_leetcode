class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        if(encodedText=="")return "";

        if(rows==1)return encodedText;

        int col=encodedText.length()/rows;

        string ans="";

        int k=0;

        vector<vector<char>> v(rows,vector<char>(col));

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                v[i][j]=encodedText[k];
                k++;
            }
        }

        cout<<"columns  "<<col<<endl;


        int x,y;


        for(int j=0;j<col;j++)
        {
            x=0;
            y=j;
            while(x<rows&&y<col)
            {
                ans+=v[x][y];
                x++;
                y++;
            }
        }

        while(!ans.empty() && ans.back() == ' ')
        ans.pop_back();

        return ans;


    }
};