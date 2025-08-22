class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        vector<vector<int>> v(3,vector<int>(3,0));

        int flag=1;

        for(int i=0;i<moves.size();i++)
        {
            v[moves[i][0]][moves[i][1]]=flag;
            flag=-flag;
        }

        if((v[0][0]+v[0][1]+v[0][2]==3)||(v[1][0]+v[1][1]+v[1][2]==3)||(v[2][0]+v[2][1]+v[2][2]==3)||(v[0][0]+v[1][0]+v[2][0]==3)||(v[0][1]+v[1][1]+v[2][1]==3)||(v[0][2]+v[1][2]+v[2][2]==3)||(v[0][0]+v[1][1]+v[2][2]==3)||(v[0][2]+v[1][1]+v[2][0]==3))
        return "A";

        if((v[0][0]+v[0][1]+v[0][2]==-3)||(v[1][0]+v[1][1]+v[1][2]==-3)||(v[2][0]+v[2][1]+v[2][2]==-3)||(v[0][0]+v[1][0]+v[2][0]==-3)||(v[0][1]+v[1][1]+v[2][1]==-3)||(v[0][2]+v[1][2]+v[2][2]==-3)||(v[0][0]+v[1][1]+v[2][2]==-3)||(v[0][2]+v[1][1]+v[2][0]==-3))
        return "B";

        if(moves.size()==9)
        return "Draw";

        return "Pending";
    }
};