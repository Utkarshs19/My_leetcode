class Solution {
public:
    bool canConvertString(string s, string t, int k) {

        set<int> st;

        if(s.length()!=t.length())return false;

        map<int,int> m;

        for(int i=0;i<s.length();i++)
        {
            int x=(t[i]-s[i]+26)%26;
            m[x]++;
        }

        for(auto i:m)
        {
            if(i.first==0)continue;

            int x=i.first;
            int y=i.second;

            long long time=x+26LL*(y-1);

            if(time>k)return false;
        }

        return true;

        return true;
        
    }
};