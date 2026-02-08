class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        unordered_map<char,vector<int>> m;

        for(int i=0;i<s.length();i++)
        {
            m[s[i]].push_back(i);
        }

        int ans=0;

        for(auto i:words)
        {
            int prev=-1;

            bool flag=true;

            for(auto c:i)
            {
                if(!m.count(c))
                {
                    flag=false;
                    break;
                }

                auto &v=m[c];
                auto it=upper_bound(v.begin(),v.end(),prev);
                if(it==v.end())
                {
                    flag=false;
                    break;
                }
                prev=*it;

            }
            if(flag)ans++;
        }
        
        return ans;
    }
};