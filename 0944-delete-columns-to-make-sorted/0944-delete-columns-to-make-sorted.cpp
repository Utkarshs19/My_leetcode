class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        vector<vector<char>> v;

        int size=0;

        for(int i=0;i<strs.size();i++)
        {   
            vector<char> c;
            for(int j=0;j<strs[i].length();j++)
            {
                c.push_back(strs[i][j]);
            }
            v.push_back(c);
        }
        int cnt=0;
        for(int i=0;i<v[0].size();i++)
        {   
            bool flag=true;
            for(int j=1;j<v.size();j++)
            {
                if(v[j][i]<v[j-1][i])
                {
                    flag=false;
                    break;
                }
            }

            if(flag==false)
            cnt++;
        }
        

        return cnt;
    }
};