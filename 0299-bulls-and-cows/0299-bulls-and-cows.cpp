class Solution {
public:
    string getHint(string secret, string guess) {

        int cnt1=0;
        int cnt2=0;
        map<char,int> m1,m2;

        for(int i=0;i<secret.length();i++)
        {
            if(secret[i]==guess[i])cnt1++;
            else
            {
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }

        for(auto i:m2)
        {
            if(m1.count(i.first))
            {
                cnt2+=min(i.second,m1[i.first]);
            }
        }

        string ans;
        ans+=to_string(cnt1)+"A"+to_string(cnt2)+"B";

        return ans;
        
    }
};