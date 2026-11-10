class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {

        int i1=0,i2=0,j1=0,j2=0;

        vector<vector<string>> ans;

        while(i2<s1.length() && j2<s2.length())
        {
            if(s1[i2]==s2[j2])
            {
                if(i2-i1+1>1)
                {
                    ans.push_back({s1.substr(i1,i2-i1),s2.substr(j1,j2-j1)});
                }
                i1=i2+1;
                i2++;
                j1=j2+1;
                j2++;
            }
            else
            {
                i2++;
                j2++;
            }
        }
        

        if(i2-i1+1>1)
        {
            ans.push_back({s1.substr(i1,i2-i1),s2.substr(j1,j2-j1)});
        }

        return ans;
    }
};