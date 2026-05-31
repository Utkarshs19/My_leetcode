class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {

        vector<vector<string>> ans;
        int n=strings.size();
        vector<bool> flag(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(flag[i])continue;
            vector<string> v;
            set<string> st;
            st.insert(strings[i]);
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<strings[i].length();k++)
                {
                    if(strings[i][k]=='z')strings[i][k]='a';
                    else
                    strings[i][k]++;
                }
                st.insert(strings[i]);
            }

            for(int j=0;j<n;j++)
            {
                if(st.count(strings[j])){flag[j]=true;
                v.push_back(strings[j]);
                }
            }
            sort(v.begin(),v.end());
            ans.push_back(v);
        }
        sort(ans.begin(),ans.end());

        return ans;

    }
};