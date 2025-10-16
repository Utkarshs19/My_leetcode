class Solution {
public:
    string stringHash(string s, int k) {

        string ans="";

        for(int i=0;i<s.length();i+=k)
        {
            string str=s.substr(i,k);
            int sum=0;

            for(int j=0;j<str.length();j++)
            {
                sum+=(str[j]-'a');
            }
            sum=sum%26;

            ans+=('a'+sum);
        }

        return ans;
        
    }
};