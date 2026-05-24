class Solution {
public:
    string betterCompression(string compressed) {

        map<char,int> m;

        int j=0;
        char c;
        int x=0;
        while(j<compressed.length())
        {
            if(isalpha(compressed[j]))
            {
                if(x!=0)
                {
                    m[c]+=x;
                }
                c=compressed[j];
                x=0;
            }
            else
            {
                x=x*10+(compressed[j]-'0');
            }
            j++;
        }
        m[c]+=x;

        string ans;

        for(auto i:m)
        {
            ans+=i.first;
            ans+=to_string(i.second);
        }
        return ans;        
    }
};