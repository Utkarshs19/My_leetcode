class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        vector<int> f(26,0);
        vector<vector<int>> freq;
        vector<bool> ans;

        for(int i=0;i<s.length();i++)
        {
            f[s[i]-'a']++;
            freq.push_back(f);
        }

        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];

            int k=queries[i][2];

            vector<int> v=freq[r];

            if(l-1>=0)
            {
                vector<int> a=freq[l-1];

                for(int j=0;j<26;j++)
                {
                    v[j]-=a[j];
                }
            }

            int cnt=0;
            for(int j=0;j<26;j++)
            {
                if(v[j]%2==1)cnt++;
            }
            
            ans.push_back(cnt/2<=k);

        }
        return ans;
    }
};