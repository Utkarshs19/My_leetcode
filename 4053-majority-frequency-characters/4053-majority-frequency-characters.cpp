class Solution {
public:
    string majorityFrequencyGroup(string s) {

        map<char,int> m;

        for(auto i:s)
        m[i]++;

        map<int , string> m1;

        for(auto i:m)
        {
            m1[i.second]+=i.first;
        }
        string ans="";
        for(auto i:m1)
        {
            if(ans.length()<=i.second.length())
            ans=i.second;
        }

        return ans;

        
        
    }
};