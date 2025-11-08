class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {

        char c1=coordinate1[0];
        int d1=coordinate1[1]-'0';

        char c2=coordinate2[0];
        int d2=coordinate2[1]-'0';

        set<char> s;
        s.insert('a');
        s.insert('c');
        s.insert('e');
        s.insert('g');

        if(s.find(c1)!=s.end())
        {
            if(s.find(c2)!=s.end())
            {
                if(d1%2==1 && d2%2==1)return true;
                else if(d1%2==0 && d2%2==0)return true;
                else return false;
            }
            else
            {
                if(d1%2==1 && d2%2==0)return true;
                else if(d1%2==0 && d2%2==1)return true;
                else return false;
            }
        }
        else
        {
            if(s.find(c2)!=s.end())
            {
                if(d1%2==0 && d2%2==1)return true;
                else if(d1%2==1 && d2%2==0)return true;
                else return false;
            }
            else
            {
                if(d1%2==0 && d2%2==0)return true;
                else if(d1%2==1 && d2%2==1)return true;
                else return false;
            }
        }

        return false;
        
    }
};