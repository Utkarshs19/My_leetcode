class Solution {
public:
    bool scoreBalance(string s) {

        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            sum+=(s[i]-'a'+1);
        }

        int cur=0;

        for(int i=0;i<s.length();i++)
        {
            cur+=(s[i]-'a'+1);
            sum-=(s[i]-'a'+1);

            if(sum==cur)return true;
        }

        return false;
        
    }
};