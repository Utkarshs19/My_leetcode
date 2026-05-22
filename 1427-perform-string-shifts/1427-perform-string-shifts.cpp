class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {

        int n=s.length();

        for(int i=0;i<shift.size();i++)
        {
            shift[i][1]%=n;
            if(shift[i][0]==0)
            {   
                string t=s.substr(shift[i][1]);
                t+=s.substr(0,shift[i][1]);

                s=t;
            }
            else
            {
                string t=s.substr(n-shift[i][1]);
                t+=s.substr(0,n-shift[i][1]);
                s=t;
            }
        }

        return s;
        
    }
};