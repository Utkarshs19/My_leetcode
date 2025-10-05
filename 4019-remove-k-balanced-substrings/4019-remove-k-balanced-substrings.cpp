class Solution {
public:
    
    string removeSubstring(string s, int k) {

        string ans="";

        for(int i=0;i<s.length();i++)
        {
            ans+=s[i];

            int sz=ans.size();

            if(sz>=2*k)
            {
                bool valid=true;
                int a=sz-2*k;
                int j=ans.length()-1;

                while(a<=j)
                {
                    if(ans[a]!='(' || ans[j]!=')')
                    {
                        valid=false;
                        break;
                    }
                    a++;
                    j--;
                }

                if(valid)
                ans.resize(sz-2*k);

            }
        }

        return ans;
    }
};