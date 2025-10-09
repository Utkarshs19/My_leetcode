class Solution {
public:
    int maxPower(string s) {

        int i=0,j=0;

        map<char,int> m;

        int ans=0;

        while(j<s.length())
        {
            m[s[j]]++;

            while(i<j && m.size()>1)
            {
                m[s[i]]--;
                if(m[s[i]]==0)m.erase(s[i]);
                i++;
            }
            cout<<j-i+1<<endl;
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
        
    }
};